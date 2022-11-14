#include "student.h"
/*******************************************************************ѧ����***********************************************************/

//���캯������
student::student(string Name, bool Sex, string id, string CardID, string College, int MaxBook) {
	name = Name;
	sex = Sex;
	ID = id;
	cardID = CardID;
	college = College;
	password = id;
}

//���ƹ��캯��
student::student(const student& s) {
	name = s.name;
	sex = s.sex;
	ID = s.ID;
	cardID = s.cardID;
	college = s.college;
	password = s.password;
}

string student::getName() {
	return name;
}

string student::getID() {
	return ID;
}

int student::getPos() {
	return bookpos;
}

bool student::changePassword(string oldPassword, string newPassword) {
	//�����ж��û��Ƿ���Ȩ���޸����룬���ж��û����
	if (password == oldPassword) {
		password = newPassword;
		return true;  //�ɹ��޸�����
		cout << "�ɹ��޸�����" << endl;
	}
	cout << "ԭ��������޷��޸�����" << endl;
	return false;  //δ�ܳɹ��޸�����
}

//�ж��û������Ƿ���ȷ��ע�⣬�˺����붼�ö�Ӧ��
bool student::isPass(string account, string pass) {
	if (account == ID && pass == password) {
		return true;
	}
	return false;
}

//��ָ��ͼ����н���
void student::borrowBook(library& lib, int pos) {
	userbook[bookpos] = lib.lendBookByNum(pos);
	bookpos++;
}

//����ֵΪ�ж��Ƿ�ɹ��黹������Ϊͼ��ݵ����ã��Լ�ѧ������ͼ�������������
bool student::returnBook(library& lib, int stuBookpos) {
	int libpos;    //�鼮��ͼ����е�λ��
	string isbn;  //ͨ���ֲ�����isbn�����鼮��ͼ����ж�Ӧ��λ�ã��Ա�黹
	int truepos = bookpos - 1 - stuBookpos;     //ѧ���ڽ����Ͽ����ı���ǵ���ģ������ҵ�����ʵ���ϵ�ͼ�������±�


	isbn = userbook[truepos].getISBN();

	//ͨ��ISBN���ұ�����ͼ����е�λ��
	libpos = lib.searchBookByISBN(isbn);
	if (libpos == -1) {  //δ���ҵ��鼮���黹ʧ��
		cout << "δ���ҵ��鼮���黹ʧ��" << endl;
		return false;
	}
	else {
		lib.regainBookByNum(libpos);   //ͼ��ݵõ��鼮��ͼ��ݹݲ�����
		cout << "�鼮��" << userbook[truepos].getname() << "���黹�ɹ�" << endl;
		//ͨ��ѭ���������û������û��鼮�б�
		int j = truepos;   //�ݴ�Ŀǰ��Ҫɾȥ���鼮���±�
		for (int i = 0; i < bookpos - truepos -1; i++) {
			userbook[j] = userbook[j + 1];
			j++;
		}
		bookpos--;//�����鼮���±��1��Ҳ�����û��鼮������1

	}

	return true;
}

void student::showInfo() {
	bool ifFirst = true;   //�ж��Ƿ��ǵ�һ����ʾ�鼮��Ϣ�����ǣ�����Ҫ��ӡ������Ϣ
	int i = 0, no = 0;  //�鼮��ţ���������軹�����
	cout << "*************************************************������Ϣ**********************************************************" << endl;
	cout.setf(ios::left);//����Ϊ�����
	//��ʾ������Ϣ
	cout << setw(18) << "������" << "|";
	cout << setw(18) << "ѧ�ţ�" << "|";
	cout << setw(18) << "У԰���ţ�" << "|";
	cout << setw(18) << "�Ա�" << "|";
	cout << setw(18) << "ѧԺ��" << "|";
	cout << setw(18) << "�����鼮������" << endl;

	//��ʾ����ѧ����Ϣ
	string s = sex ? "Ů" : "��";  //������Ŀ�������ȡ�Ա�
	cout << setw(18) << name << "|";
	cout << setw(18) << ID << "|";
	cout << setw(18) << cardID << "|";
	cout << setw(18) << s << "|";  
	cout << setw(18) << college << "|";
	cout << setw(18) << bookpos << endl;

	cout << "*************************************************�������**********************************************************" << endl;
	if (bookpos == 0) {
		cout << "û�н��ļ�¼" << endl;
	}
	else {
		i = bookpos;//�ݴ��鼮λ��
		while (i != 0) {
			if (ifFirst) {
				cout.setf(ios::left);//����Ϊ�����
				cout << setw(18) << "��ţ�" << "|";
				cout << setw(18) << "������" << "|";
				cout << setw(18) << "���ߣ�" << "|";
				cout << setw(18) << "�����磺" << "|";
				cout << setw(18) << "ISBN��" << endl;
				ifFirst = false;//��֤���ж������һ�κ������ù�����ֻ������һ��
			}
			cout << setw(18) << no << "|";
			userbook[i - 1].show(0); //����֮��bookpos����1�������1���ܿ��������鼮
			i--;
			no++;
		}
		
	}

	
	


}



