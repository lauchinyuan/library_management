#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <iomanip>
using namespace std;
#include "book.h"
#include "library.h"
/********************************************************************学生类*************************************************/
class student {
	string name;      //姓名
	bool sex;         //性别，true为女性，false为男性。
	string ID;        //学号，同时也是系统登录账号
	string cardID;    //学生校卡ID
	string password;  //学生登录系统的密码，默认为学号
	string college;   //学生所在学院
	book userbook[10];//默认学生最大借书量为10本
	int bookpos = 0;  //书籍标号索引，同时也是当前借阅的书籍数量

public:

	//构造函数
	student(string Name = "****", bool Sex = false, string id = "****", string CardID = "****", string College = "****", int MaxBook = 3);
	~student() {}; //析构函数
	student(const student&); //复制构造函数
	string getName();        //获取学生姓名的接口
	string getID();          //获取学生学号的接口
	int getPos();             //获取学生书籍量的接口
	bool changePassword(string, string);  //更改密码
	bool isPass(string, string);          //判断用户是否密码正确
	void showInfo();                    //显示借阅信息
	void borrowBook(library&, int);   //借书
	bool returnBook(library&, int);   //还书

	//运算符重载函数
	student& operator=(const student& s) {
		// 如果是对象本身, 则直接返回
		if (this == &s) {
			return *this;
		}
		// 复制等号右边对象的成员值到等号左边对象的成员
		this->cardID = s.cardID;
		this->college = s.college;
		this->ID = s.ID;
		this->name = s.name;
		this->password = s.password;
		this->sex = s.sex;
		return *this;
	}

};



#endif

