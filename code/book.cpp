/******************************************************************����ͼ����***********************************************************************/
#include"book.h"
//���캯��
book::book(string Name, string Author, string isbn, string Press) {
	name = Name;
	author = Author;
	ISBN = isbn;
	press = Press;
}

//���ƹ��캯��������const�ؼ�����Ϊ�˷�ֹ������޸�
book::book(const book& b) {
	name = b.name;
	author = b.author;
	press = b.press;
	ISBN = b.ISBN;
}

//��ʾ�鼮��Ϣ������Ĳ��������Ƿ�Ҫ��ӡ����
void book::show(bool title) {
	
	cout.setf(ios::left);//����Ϊ�����
	if (title) {//��Ҫ��ʾ������Ϣ
		cout << setw(18) << "������" << "|";
		cout << setw(18) << "���ߣ�" << "|";
		cout << setw(18) << "�����磺" << "|";
		cout << setw(18) << "ISBN��" << endl;
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

/*******************************************************************ͼ����е��鼮��***********************************************************/

//��ʾ�鼮��Ϣ�������ͬ��ͬ��
void libraryBook::show(bool title) {
	cout.setf(ios::left);//����Ϊ�����

	if (title) {  //��Ҫ��ʾ����
		cout << "������" << setw(10) << name << "|";
		cout << "���ߣ�" << setw(10) << author << "|";
		cout << "ISBN��" << setw(10) << ISBN << "|";
		cout << "�ݲ�������" << setw(10) << quantity << "|";
		cout << "�ɽ�������" << setw(10) << nowQuantity << endl;
	}
	
}



