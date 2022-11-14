#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include <iomanip>
using namespace std;
#include "student.h"
#include "Mybase.h"
/*******************************************************************ͼ�����***********************************************************/
class library {
	string password;                 //ͼ�����Ա���룬Ĭ��1234
	int maxQuantity;                 //���ݲ�ͼ��������Ĭ��Ϊ100��
	int trueQuantity;			     //ʵ�ʲ���Ʒ��
	int pos;                         //�˱������ڼ�¼��ǰ�������鼮���������λ��
	int stupos;                      //��ǵ�ǰ������ѧ����������λ��
	int allQuantity;                 //�ݲ�ͼ������
	int libNowQuantity;              //ͼ��ݵ�ǰͼ������
	libraryBook book_collect[300];   //�ݲ��鼮

public:
	library(int max = 100);               //���캯��
	~library() {};						  //��������
	library(const library&);              //���ƹ��캯��
	bool changePassword(string, string);  //����ͼ�����Ա����
	bool isPass(string);                  //�ж������Ƿ���ȷ
	void addBook(string Name, string Author, string isbn, string Press, int Quantity); //¼�����鼮
	int* searchBook(string);				  //�����鼮
	int searchBookByISBN(string);            //ͨ��ISBN�����鼮��ͼ����е�λ�ã���ΪISBN��Ψһ��
	void showInfoByNum(int*);           //��ʾָ���±���鼮��Ϣ���������������չʾ
	book lendBookByNum(int i);         //ͨ���±����鼮
	void regainBookByNum(int i);       //ͨ���±�黹�鼮
	void showBookList();              //�鿴ͼ����鵥
	void showLibInfo();               //�鿴��ǰͼ��ݲ������
};


#endif

