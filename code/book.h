#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <iomanip>
using namespace std;
//防止重复引入
/*******************************************************************基本书籍类***********************************************************/
class book {
protected:
	string name;   //书名
	string author; //作者
	string ISBN;   //ISBN(国际标准书号)
	string press;  //出版社

public:
	book(string Name = "****", string Author = "****",
		string isbn = "****", string Press = "****"); //构造函数
	~book() {} //析构函数，默认进行空处理
	book(const book&);//复制构造函数
	string getISBN();  //获取本书标识号的接口，用于之后的搜索等操作
	string getname();
	void show(bool);  //显示书籍信息
};

/*****************************************************************图书馆中的书籍类**************************************************************************************/
//图书馆中的书籍有特殊的属性（如图书数量、可借书数量），以及特有的操作（编辑图书信息等）

//从基本图书类中派生出的图书馆图书类
class libraryBook : public book {
	int quantity;  //图书数量
	int nowQuantity;  //现存图书数量
public:
	//构造函数
	libraryBook(string Name = "****", string Author = "****",
		string isbn = "****", string Press = "****",
		int Quantity = 0) :book(Name, Author, isbn, Press) {
		quantity = Quantity;
		nowQuantity = Quantity; //初始化时馆藏书籍默认未借出
	}

	//析构函数，默认进行空处理
	~libraryBook() {}

	//复制构造函数
	libraryBook(const libraryBook& b) :book(b) {
		quantity = b.quantity;
		nowQuantity = b.nowQuantity;
	}

	void show(bool);            //显示书籍信息，传入true时，会打印标题信息
	friend class library;      //将图书馆类设为书籍类的友元类，方可访问图书的私有数据

};


#endif


