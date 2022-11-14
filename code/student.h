#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <iomanip>
using namespace std;
#include "book.h"
#include "library.h"
/********************************************************************ѧ����*************************************************/
class student {
	string name;      //����
	bool sex;         //�Ա�trueΪŮ�ԣ�falseΪ���ԡ�
	string ID;        //ѧ�ţ�ͬʱҲ��ϵͳ��¼�˺�
	string cardID;    //ѧ��У��ID
	string password;  //ѧ����¼ϵͳ�����룬Ĭ��Ϊѧ��
	string college;   //ѧ������ѧԺ
	book userbook[10];//Ĭ��ѧ����������Ϊ10��
	int bookpos = 0;  //�鼮���������ͬʱҲ�ǵ�ǰ���ĵ��鼮����

public:

	//���캯��
	student(string Name = "****", bool Sex = false, string id = "****", string CardID = "****", string College = "****", int MaxBook = 3);
	~student() {}; //��������
	student(const student&); //���ƹ��캯��
	string getName();        //��ȡѧ�������Ľӿ�
	string getID();          //��ȡѧ��ѧ�ŵĽӿ�
	int getPos();             //��ȡѧ���鼮���Ľӿ�
	bool changePassword(string, string);  //��������
	bool isPass(string, string);          //�ж��û��Ƿ�������ȷ
	void showInfo();                    //��ʾ������Ϣ
	void borrowBook(library&, int);   //����
	bool returnBook(library&, int);   //����

	//��������غ���
	student& operator=(const student& s) {
		// ����Ƕ�����, ��ֱ�ӷ���
		if (this == &s) {
			return *this;
		}
		// ���ƵȺ��ұ߶���ĳ�Աֵ���Ⱥ���߶���ĳ�Ա
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

