#include "student.h"
/*******************************************************************学生类***********************************************************/

//构造函数定义
student::student(string Name, bool Sex, string id, string CardID, string College, int MaxBook) {
	name = Name;
	sex = Sex;
	ID = id;
	cardID = CardID;
	college = College;
	password = id;
}

//复制构造函数
student::student(const student& s) {
	name = s.name;
	sex = s.sex;
	ID = s.ID;
	cardID = s.cardID;
	college = s.college;
	password = s.password;
}

string student::getName() {
	return name;
}

string student::getID() {
	return ID;
}

int student::getPos() {
	return bookpos;
}

bool student::changePassword(string oldPassword, string newPassword) {
	//首先判断用户是否有权限修改密码，即判断用户身份
	if (password == oldPassword) {
		password = newPassword;
		return true;  //成功修改密码
		cout << "成功修改密码" << endl;
	}
	cout << "原密码错误，无法修改密码" << endl;
	return false;  //未能成功修改密码
}

//判断用户密码是否正确，注意，账号密码都得对应上
bool student::isPass(string account, string pass) {
	if (account == ID && pass == password) {
		return true;
	}
	return false;
}

//从指定图书馆中借书
void student::borrowBook(library& lib, int pos) {
	userbook[bookpos] = lib.lendBookByNum(pos);
	bookpos++;
}

//返回值为判断是否成功归还，输入为图书馆的引用，以及学生类中图书对象数组的序号
bool student::returnBook(library& lib, int stuBookpos) {
	int libpos;    //书籍在图书馆中的位置
	string isbn;  //通过局部变量isbn搜索书籍在图书馆中对应的位置，以便归还
	int truepos = bookpos - 1 - stuBookpos;     //学生在界面上看到的编号是倒序的，这里找到的是实际上的图书数组下标


	isbn = userbook[truepos].getISBN();

	//通过ISBN查找本书在图书馆中的位置
	libpos = lib.searchBookByISBN(isbn);
	if (libpos == -1) {  //未能找到书籍，归还失败
		cout << "未能找到书籍，归还失败" << endl;
		return false;
	}
	else {
		lib.regainBookByNum(libpos);   //图书馆得到书籍，图书馆馆藏增加
		cout << "书籍《" << userbook[truepos].getname() << "》归还成功" << endl;
		//通过循环操作将用户更新用户书籍列表
		int j = truepos;   //暂存目前需要删去的书籍的下标
		for (int i = 0; i < bookpos - truepos -1; i++) {
			userbook[j] = userbook[j + 1];
			j++;
		}
		bookpos--;//索引书籍的下标减1，也代表用户书籍数量减1

	}

	return true;
}

void student::showInfo() {
	bool ifFirst = true;   //判断是否是第一次显示书籍信息，若是，则需要打印标题信息
	int i = 0, no = 0;  //书籍编号，方便后续借还书操作
	cout << "*************************************************基本信息**********************************************************" << endl;
	cout.setf(ios::left);//设置为左对齐
	//显示标题信息
	cout << setw(18) << "姓名：" << "|";
	cout << setw(18) << "学号：" << "|";
	cout << setw(18) << "校园卡号：" << "|";
	cout << setw(18) << "性别：" << "|";
	cout << setw(18) << "学院：" << "|";
	cout << setw(18) << "借阅书籍数量：" << endl;

	//显示具体学生信息
	string s = sex ? "女" : "男";  //利用三目运算符获取性别
	cout << setw(18) << name << "|";
	cout << setw(18) << ID << "|";
	cout << setw(18) << cardID << "|";
	cout << setw(18) << s << "|";  
	cout << setw(18) << college << "|";
	cout << setw(18) << bookpos << endl;

	cout << "*************************************************借阅情况**********************************************************" << endl;
	if (bookpos == 0) {
		cout << "没有借阅记录" << endl;
	}
	else {
		i = bookpos;//暂存书籍位置
		while (i != 0) {
			if (ifFirst) {
				cout.setf(ios::left);//设置为左对齐
				cout << setw(18) << "编号：" << "|";
				cout << setw(18) << "书名：" << "|";
				cout << setw(18) << "作者：" << "|";
				cout << setw(18) << "出版社：" << "|";
				cout << setw(18) << "ISBN：" << endl;
				ifFirst = false;//保证此判断语句在一次函数调用过程中只会运行一次
			}
			cout << setw(18) << no << "|";
			userbook[i - 1].show(0); //借书之后将bookpos加了1，这里减1才能看见所借书籍
			i--;
			no++;
		}
		
	}

	
	


}



