#include "library.h"
/*******************************************************************ͼ�����***********************************************************/

//���캯��
library::library(int max) {
	maxQuantity = max;      
	trueQuantity = 0;     //ʵ�ʲ�������ʼ��Ϊ0
	allQuantity = 0;      //ʵ�ʵ�ͼ��������ʼ��Ϊ0
	libNowQuantity = 0;  //��ʼ��Ϊ0
	pos = 0;             //Ĭ�ϵĲ���λ��0��ʼ
	password = "1234";   //Ĭ�ϵ�����
}

//���ƹ��캯��
library::library(const library& lib) {
	maxQuantity = lib.maxQuantity;
	trueQuantity = lib.trueQuantity;
	allQuantity = lib.allQuantity;
	libNowQuantity = lib.libNowQuantity;
	pos = lib.pos;
	password = lib.password;
}


//�޸�����
bool library::changePassword(string oldPassword, string newPassword) {
	//�����ж��û��Ƿ���Ȩ���޸����룬���ж��û����
	if (password == oldPassword) {
		cout << "\n�ɹ��޸�����" << endl;
		password = newPassword;
		return true;  //�ɹ��޸�����
	}
	cout << "ԭ��������޷��޸�����" << endl;
	return false;

}

//�ж��û��Ƿ�Ϸ�
bool library::isPass(string Password) {
	if (Password == password) {
		return true;
	}
	return false;
}

//¼�����鼮
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
		pos++;   //����ͼ����������
	}
	else {
		cout << "�Ѵﵽ���ݲ�����" << endl;
	}

}

//ͨ�������ַ�������ȫ�����������鼮������������н�����±꣨�������������ʽ��
int* library::searchBook(string str) {
	int loc[51] = {0};   //��¼�鼮������ȡ�ŵ����飬�����趨ÿ�������Ѱ��50���鼮
	int j = 0;

	//ѭ������ͼ����еĲ��飬��������ĺ����е�
	for (int i = 0; i < trueQuantity; i++) {
		//�ж��Ƿ�������ؼ��ֵ��鼮
		if (book_collect[i].author == str || book_collect[i].name == str || book_collect[i].ISBN == str || book_collect[i].press == str) {
			//�ҵ��鼮
			loc[j] = i;   //��¼�鼮�±�
			j++;
			if (j >= 50) {     //�������
				cout << "���ϵĽ�����϶࣬Ϊ����Ѱ��ǰ50��" << endl;
				break; //����ѭ��
			}
		}
	}
	cout << "���ҵ�" << j << "�ʽ����ллʹ�á�" << endl;

	//����β���ӱ��
	loc[j] = -1;
	showInfoByNum(loc);      //��ʾ�ҵ���ͼ����Ϣ
	return loc;              //���������±�
}


//ͨ��ISBN�����鼮��ͼ����е�λ��
int library::searchBookByISBN(string str) {
	for (int i = 0; i < trueQuantity; i++) {
		if (book_collect[i].ISBN == str) {
			return i;
		}
	}
	return -1;
}

//������ʾ�鼮��Ϣ��ͨ�������±����
void library::showInfoByNum(int* i) {
	int n = 0;
	cout.setf(ios::left);//����Ϊ�����
	//��ʾ������Ϣ
	cout << setw(18) << "��ȡ��ţ�" << "|";
	cout << setw(18) << "������" << "|";
	cout << setw(18) << "���ߣ�" << "|";
	cout << setw(18) << "ISBN��" << "|";
	cout << setw(18) << "�ݲ�����" << "|";
	cout << setw(18) << "�ɽ�������" << endl;

	while (i[n] != -1) {   //��������,��������-1��Ϊ������־,con(δ���ҵ����ϸ�����������ʾ)
		cout << setw(18) << i[n] << "|";
		cout << setw(18) << book_collect[i[n]].name << "|";
		cout << setw(18) << book_collect[i[n]].author << "|";
		cout << setw(18) << book_collect[i[n]].ISBN << "|";
		cout << setw(18) << book_collect[i[n]].quantity << "|";
		cout << setw(18) << book_collect[i[n]].nowQuantity << endl;
		n++;
	}
}


//ͨ���鼮������������
book library::lendBookByNum(int i) {
	book b;
	if (book_collect[i].nowQuantity > 0) { //�ɽ�
		book_collect[i].nowQuantity--;
		libNowQuantity--;     //ͼ����ܲ�����������
		b = book_collect[i];   //�õ��˸�ֵ���ݹ���
		cout << "�鼮��"<<book_collect[i].getname() <<"���ɹ������ллʹ��" << endl;
	}
	else {
		cout << "�Բ��𣬸����ѽ�գ����´�����" << endl;
	}
	return b;

}

//ͨ���±�黹�鼮
void library::regainBookByNum(int i) {
	book_collect[i].nowQuantity++;
	libNowQuantity++;   //ʵ�ʲ�����������
}

//�鿴ͼ����鵥
void library::showBookList() {
	int n = 0;
	cout << "****************************************************�ݲ�ͼ���б�************************************************" << endl;
	cout.setf(ios::left);//����Ϊ�����
	//��ʾ������Ϣ
	cout << setw(18) << "��ȡ��ţ�" << "|";
	cout << setw(18) << "������" << "|";
	cout << setw(18) << "���ߣ�" << "|";
	cout << setw(18) << "�����磺" << "|";
	cout << setw(18) << "ISBN��" << "|";
	cout << setw(18) << "�ݲ�����" << "|";
	cout << setw(18) << "�ɽ�������" << endl;

	while (n < pos) {   //��������,��������-1��Ϊ������־,con(δ���ҵ����ϸ�����������ʾ)
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

//�鿴��ǰͼ��ݲ������
void library::showLibInfo() {
	cout << "*************************************************��ǰͼ��������************************************************" << endl;
	cout.setf(ios::left);//����Ϊ�����
//��ʾ������Ϣ
	cout << setw(18) << "������������" << "|";
	cout << setw(18) << "��ͼ�����ࣺ" << "|";
	cout << setw(18) << "ͼ����������" << "|";
	cout << setw(18) << "��ǰ���������" << "|";
	cout << setw(18) << "��ǰ�ݲ�������" << endl;

	cout << setw(18) << maxQuantity << "|";
	cout << setw(18) << pos << "|";
	cout << setw(18) << allQuantity << "|";
	cout << setw(18) << allQuantity - libNowQuantity << "|";
	cout << setw(18) << libNowQuantity << endl;
	cout << nStart(112) << endl;

}




