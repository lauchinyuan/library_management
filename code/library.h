#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include <iomanip>
using namespace std;
#include "student.h"
#include "Mybase.h"
/*******************************************************************图书馆类***********************************************************/
class library {
	string password;                 //图书管理员密码，默认1234
	int maxQuantity;                 //最大馆藏图书容量，默认为100种
	int trueQuantity;			     //实际藏书品种
	int pos;                         //此变量用于记录当前操作的书籍对象数组的位置
	int stupos;                      //标记当前操作的学生对象数组位置
	int allQuantity;                 //馆藏图书数量
	int libNowQuantity;              //图书馆当前图书数量
	libraryBook book_collect[300];   //馆藏书籍

public:
	library(int max = 100);               //构造函数
	~library() {};						  //析构函数
	library(const library&);              //复制构造函数
	bool changePassword(string, string);  //更改图书管理员密码
	bool isPass(string);                  //判断密码是否正确
	void addBook(string Name, string Author, string isbn, string Press, int Quantity); //录入新书籍
	int* searchBook(string);				  //查找书籍
	int searchBookByISBN(string);            //通过ISBN查找书籍在图书馆中的位置，因为ISBN是唯一的
	void showInfoByNum(int*);           //显示指定下标的书籍信息，用于搜索结果的展示
	book lendBookByNum(int i);         //通过下标借出书籍
	void regainBookByNum(int i);       //通过下标归还书籍
	void showBookList();              //查看图书馆书单
	void showLibInfo();               //查看当前图书馆藏书情况
};


#endif

