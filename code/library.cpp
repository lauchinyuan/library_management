#include "library.h"
/*******************************************************************图书馆类***********************************************************/

//构造函数
library::library(int max) {
	maxQuantity = max;      
	trueQuantity = 0;     //实际藏书量初始化为0
	allQuantity = 0;      //实际的图书数量初始化为0
	libNowQuantity = 0;  //初始化为0
	pos = 0;             //默认的查找位从0开始
	password = "1234";   //默认的密码
}

//复制构造函数
library::library(const library& lib) {
	maxQuantity = lib.maxQuantity;
	trueQuantity = lib.trueQuantity;
	allQuantity = lib.allQuantity;
	libNowQuantity = lib.libNowQuantity;
	pos = lib.pos;
	password = lib.password;
}


//修改密码
bool library::changePassword(string oldPassword, string newPassword) {
	//首先判断用户是否有权限修改密码，即判断用户身份
	if (password == oldPassword) {
		cout << "\n成功修改密码" << endl;
		password = newPassword;
		return true;  //成功修改密码
	}
	cout << "原密码错误，无法修改密码" << endl;
	return false;

}

//判断用户是否合法
bool library::isPass(string Password) {
	if (Password == password) {
		return true;
	}
	return false;
}

//录入新书籍
void library::addBook(string Name, string Author, string isbn, string Press, int Quantity) {
	if (trueQuantity <= maxQuantity) {
		book_collect[pos].author = Author;
		book_collect[pos].ISBN = isbn;
		book_collect[pos].name = Name;
		book_collect[pos].press = Press;
		book_collect[pos].quantity = Quantity;
		book_collect[pos].nowQuantity = Quantity;
		trueQuantity++;
		allQuantity += Quantity;
		libNowQuantity += Quantity;
		pos++;   //增加图书种类数量
	}
	else {
		cout << "已达到最大馆藏数量" << endl;
	}

}

//通过输入字符串进行全搜索，返回书籍对象数组的所有结果的下标（以整形数组的形式）
int* library::searchBook(string str) {
	int loc[51] = {0};   //记录书籍所在索取号的数组，这里设定每次最多搜寻到50种书籍
	int j = 0;

	//循环遍历图书馆中的藏书，包含借出的和现有的
	for (int i = 0; i < trueQuantity; i++) {
		//判断是否有满足关键字的书籍
		if (book_collect[i].author == str || book_collect[i].name == str || book_collect[i].ISBN == str || book_collect[i].press == str) {
			//找到书籍
			loc[j] = i;   //记录书籍下标
			j++;
			if (j >= 50) {     //结果过多
				cout << "符合的结果数较多，为您搜寻到前50项" << endl;
				break; //结束循环
			}
		}
	}
	cout << "共找到" << j << "笔结果，谢谢使用。" << endl;

	//数组尾部加标记
	loc[j] = -1;
	showInfoByNum(loc);      //显示找到的图书信息
	return loc;              //返回索引下标
}


//通过ISBN查找书籍在图书馆中的位置
int library::searchBookByISBN(string str) {
	for (int i = 0; i < trueQuantity; i++) {
		if (book_collect[i].ISBN == str) {
			return i;
		}
	}
	return -1;
}

//批量显示书籍信息，通过数组下标访问
void library::showInfoByNum(int* i) {
	int n = 0;
	cout.setf(ios::left);//设置为左对齐
	//显示标题信息
	cout << setw(18) << "索取编号：" << "|";
	cout << setw(18) << "书名：" << "|";
	cout << setw(18) << "作者：" << "|";
	cout << setw(18) << "ISBN：" << "|";
	cout << setw(18) << "馆藏数量" << "|";
	cout << setw(18) << "可借数量：" << endl;

	while (i[n] != -1) {   //遍历数组,该数组以-1作为结束标志,con(未查找到在上个函数进行提示)
		cout << setw(18) << i[n] << "|";
		cout << setw(18) << book_collect[i[n]].name << "|";
		cout << setw(18) << book_collect[i[n]].author << "|";
		cout << setw(18) << book_collect[i[n]].ISBN << "|";
		cout << setw(18) << book_collect[i[n]].quantity << "|";
		cout << setw(18) << book_collect[i[n]].nowQuantity << endl;
		n++;
	}
}


//通过书籍数组索引借书
book library::lendBookByNum(int i) {
	book b;
	if (book_collect[i].nowQuantity > 0) { //可借
		book_collect[i].nowQuantity--;
		libNowQuantity--;     //图书馆总藏书数量减少
		b = book_collect[i];   //用到了赋值兼容规则
		cout << "书籍《"<<book_collect[i].getname() <<"》成功借出，谢谢使用" << endl;
	}
	else {
		cout << "对不起，该书已借空，请下次再来" << endl;
	}
	return b;

}

//通过下标归还书籍
void library::regainBookByNum(int i) {
	book_collect[i].nowQuantity++;
	libNowQuantity++;   //实际藏书数量增加
}

//查看图书馆书单
void library::showBookList() {
	int n = 0;
	cout << "****************************************************馆藏图书列表************************************************" << endl;
	cout.setf(ios::left);//设置为左对齐
	//显示标题信息
	cout << setw(18) << "索取编号：" << "|";
	cout << setw(18) << "书名：" << "|";
	cout << setw(18) << "作者：" << "|";
	cout << setw(18) << "出版社：" << "|";
	cout << setw(18) << "ISBN：" << "|";
	cout << setw(18) << "馆藏数量" << "|";
	cout << setw(18) << "可借数量：" << endl;

	while (n < pos) {   //遍历数组,该数组以-1作为结束标志,con(未查找到在上个函数进行提示)
		cout << setw(18) << n << "|";
		cout << setw(18) << book_collect[n].name << "|";
		cout << setw(18) << book_collect[n].author << "|";
		cout << setw(18) << book_collect[n].press << "|";
		cout << setw(18) << book_collect[n].ISBN << "|";
		cout << setw(18) << book_collect[n].quantity << "|";
		cout << setw(18) << book_collect[n].nowQuantity << endl;
		n++;
	}
	cout << nStart(112)<< endl;
}

//查看当前图书馆藏书情况
void library::showLibInfo() {
	cout << "*************************************************当前图书借阅情况************************************************" << endl;
	cout.setf(ios::left);//设置为左对齐
//显示标题信息
	cout << setw(18) << "最大藏书容量：" << "|";
	cout << setw(18) << "总图书种类：" << "|";
	cout << setw(18) << "图书总数量：" << "|";
	cout << setw(18) << "当前借出数量：" << "|";
	cout << setw(18) << "当前馆藏数量：" << endl;

	cout << setw(18) << maxQuantity << "|";
	cout << setw(18) << pos << "|";
	cout << setw(18) << allQuantity << "|";
	cout << setw(18) << allQuantity - libNowQuantity << "|";
	cout << setw(18) << libNowQuantity << endl;
	cout << nStart(112) << endl;

}




