/******************************************************************基本图书类***********************************************************************/
#include"book.h"
//构造函数
book::book(string Name, string Author, string isbn, string Press) {
	name = Name;
	author = Author;
	ISBN = isbn;
	press = Press;
}

//复制构造函数，加入const关键字是为了防止意外的修改
book::book(const book& b) {
	name = b.name;
	author = b.author;
	press = b.press;
	ISBN = b.ISBN;
}

//显示书籍信息，传入的参数表明是否要打印标题
void book::show(bool title) {
	
	cout.setf(ios::left);//设置为左对齐
	if (title) {//需要显示标题信息
		cout << setw(18) << "书名：" << "|";
		cout << setw(18) << "作者：" << "|";
		cout << setw(18) << "出版社：" << "|";
		cout << setw(18) << "ISBN：" << endl;
	}
	cout << setw(18) << name << "|";
	cout << setw(18) << author << "|";
	cout << setw(18) << press << "|";
	cout << setw(18) << ISBN << endl;
}

string book::getISBN() {
	return ISBN;
}

string  book::getname() {
	return name;
}

/*******************************************************************图书馆中的书籍类***********************************************************/

//显示书籍信息，与基类同名同参
void libraryBook::show(bool title) {
	cout.setf(ios::left);//设置为左对齐

	if (title) {  //需要显示标题
		cout << "书名：" << setw(10) << name << "|";
		cout << "作者：" << setw(10) << author << "|";
		cout << "ISBN：" << setw(10) << ISBN << "|";
		cout << "馆藏数量：" << setw(10) << quantity << "|";
		cout << "可借数量：" << setw(10) << nowQuantity << endl;
	}
	
}



