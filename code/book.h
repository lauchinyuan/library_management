#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <iomanip>
using namespace std;
//��ֹ�ظ�����
/*******************************************************************�����鼮��***********************************************************/
class book {
protected:
	string name;   //����
	string author; //����
	string ISBN;   //ISBN(���ʱ�׼���)
	string press;  //������

public:
	book(string Name = "****", string Author = "****",
		string isbn = "****", string Press = "****"); //���캯��
	~book() {} //����������Ĭ�Ͻ��пմ���
	book(const book&);//���ƹ��캯��
	string getISBN();  //��ȡ�����ʶ�ŵĽӿڣ�����֮��������Ȳ���
	string getname();
	void show(bool);  //��ʾ�鼮��Ϣ
};

/*****************************************************************ͼ����е��鼮��**************************************************************************************/
//ͼ����е��鼮����������ԣ���ͼ���������ɽ������������Լ����еĲ������༭ͼ����Ϣ�ȣ�

//�ӻ���ͼ��������������ͼ���ͼ����
class libraryBook : public book {
	int quantity;  //ͼ������
	int nowQuantity;  //�ִ�ͼ������
public:
	//���캯��
	libraryBook(string Name = "****", string Author = "****",
		string isbn = "****", string Press = "****",
		int Quantity = 0) :book(Name, Author, isbn, Press) {
		quantity = Quantity;
		nowQuantity = Quantity; //��ʼ��ʱ�ݲ��鼮Ĭ��δ���
	}

	//����������Ĭ�Ͻ��пմ���
	~libraryBook() {}

	//���ƹ��캯��
	libraryBook(const libraryBook& b) :book(b) {
		quantity = b.quantity;
		nowQuantity = b.nowQuantity;
	}

	void show(bool);            //��ʾ�鼮��Ϣ������trueʱ�����ӡ������Ϣ
	friend class library;      //��ͼ�������Ϊ�鼮�����Ԫ�࣬���ɷ���ͼ���˽������

};


#endif


