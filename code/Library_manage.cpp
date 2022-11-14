// Library_manage.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <iomanip>
using namespace std;

#include "book.h"
#include "student.h"
#include "library.h"
#include "Mybase.h"

#define STUDENT_NUM 10   //学生容量
/*****************************************************主函数*************************************************************/
int main()
{
	int select;           //用户选择的操作编码
	int identity;        //身份编码，1为读者，2位学生
	string ID, password; //登录本系统的账号密码
	bool security = false; //判断用户是否合法，1合法，0非法。
	int contin = 0;     //循环状态，进入系统提示输入身份，用于在某些情况下，用户需要重新输入，默认为0不必重复循环
	library lib(200);
	student s[STUDENT_NUM];     //学生，容量设为STUDENT_NUM
	int stupos;         //学生在数组的下标
	string strtemp[4];  //用于接收用户输入的字符串
	int inttemp[3];     //用于接收用户输入的整数


	//使用了运算符重载函数
	s[1] = student("李剑青", false, "2020", "292564", "电子与信息工程", 3);
	s[0] = student("赵一梓", false, "2018133090", "292561", "计算机与软件", 3);  //学号为2018133090
	s[3] = student("陈佐", false, "2018133020", "291568", "经济学院", 3);    //学号为2018133020

	//增加一些基础的图书信息，方便测试
	lib.addBook("陶渊明集译注", "孟二冬", "9787101116533", "中华书局", 3);
	lib.addBook("丹鉛總録校證", "(明) 楊慎", "9787101139396", "中华书局", 3);
	lib.addBook("台湾历史纲要", "陈孔立", "9787510890383", "九州出版社", 3);
	lib.addBook("二月河论", "郝敬波", "9787521207354", "作家出版社", 3);
	lib.addBook("虚无的十字架", "东野圭吾", "9787540487416", "湖南文艺出版社", 3);


	//通过外层while循环确保整个程序可以不断运行
	while (1) {

		//以下while循环为用户登录界面
		while (1) {
			security = 0;  //每次进入循环都要将此标志置为false，保证安全，只有用户密码正确才能进入系统
			cout << "欢迎使用本系统，请选择你的身份。" << endl;
			cout << nStart(70) << endl;
			cout.setf(ios::left);//设置为左对齐
			cout << setw(18) << "1" << "|";
			cout << setw(18) << "2" << "|"<< endl;
			cout << setw(18) << "读者用户" << "|";
			cout << setw(18) << "图书管理员" << "|" << endl;
			cout << nStart(70) << endl;
			cout << "输入：";
			cin >> identity;
			cout << "\n\n";
			switch (identity)
			{
			case 1:   //读者用户
				contin = 0;  //可以退出while循环
				cout << "亲爱的读者用户，欢迎您" << endl;
				cout << "请输入您的学号：";
				cin >> ID;
				cout << "请输入您的密码（默认密码为学号）：";
				cin >> password;
				int i;
				for (i = 0; i < STUDENT_NUM; i++) {
					if (s[i].isPass(ID, password)) { //找到该学生，且账号密码正确
						cout << "\n\n";
						cout << "登录成功，欢迎您，" << s[i].getName() << endl;   //调用接口，获取用户名，作欢迎界面
						stupos = i;          //学生索引
						security = true;  //合法用户
					}

				}
				if (i == STUDENT_NUM && security == false) {  //查找了所有学生
					cout << "查无此生或者密码错误" << endl;
					cout << "\n\n";
					security = false; //非法用户
					contin++;//继续while循环
				}
				break;


			case 2:  //管理员用户
				contin = 0;  //可以退出while循环
				cout << "亲爱的图书管理员管理员，欢迎您" << endl;
				cout << "请输入您管理员的密码（默认1234）：";
				cin >> password;
				if (lib.isPass(password)) {
					cout << "\n" << endl;
					cout << "登录成功，欢迎你，管理员"<< endl;
					security = 1;
				}
				else {//密码错误
					cout << "密码错误" << endl;
					cout << "\n\n";
					security = 0;
					contin++;//继续循环
				}
				break;
			default:
				contin++;  //重复while循环
				cout << "输入有误，请重新输入" << endl;

				break;
			}


			//退出本循环的条件
			if (contin == 0) {//不必重复判断用户身份，退出循环
				break;
			}
			else if (contin == 5) {
				cout << "\n";
				cout << "错误次数过多，程序退出终止" << endl;
				return 0;
			}

		}

		contin = 0;
		//运行到这里说明用户已经登录成功

		//依据用户身份让用户选择操作，前面的switch语句中保证了identity在这里只能是1或者2
		//此while循环用于确定用户所需的操作
		while (1) {
			if (identity == 1) {//读者
				cout << "请选择你所需的操作：" << endl;
				cout << nStart(115) << endl;
				cout.setf(ios::left);//设置为左对齐
				cout << setw(18) << "1" << "|";
				cout << setw(18) << "2" << "|";
				cout << setw(18) << "3" << "|";
				cout << setw(18) << "4" << "|";
				cout << setw(18) << "5" << "|";
				cout << setw(18) << "6" << "|" << endl;
				cout << setw(18) << "借书" << "|";
				cout << setw(18) << "还书" << "|";
				cout << setw(18) << "查看借阅信息" << "|";
				cout << setw(18) << "查找书籍" << "|";
				cout << setw(18) << "藏书列表" << "|";
				cout << setw(18) << "修改密码" << "|" << endl;
				cout << nStart(115) << endl;
				cout << "输入：";
				cin >> select;
				cout << "\n\n";
				/*判断输入是否合法*/
				switch (select) {
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					contin = 0;
					break;
				default:
					cout << "\n";
					cout << "输入非法，请重新输入" << endl;
					contin++;
				}

			}
			else { //图书管理员
				contin = 0;
				cout << "请选择你所需的操作：" << endl;

				cout << nStart(115) << endl;
				cout.setf(ios::left);//设置为左对齐
				cout << setw(18) << "1" << "|";
				cout << setw(18) << "2" << "|";
				cout << setw(18) << "3" << "|";
				cout << setw(18) << "4" << "|";
				cout << setw(18) << "5" << "|";
				cout << setw(18) << "6" << "|" << endl;
				cout << setw(18) << "录入书籍" << "|";
				cout << setw(18) << "查看馆藏图书列表" << "|";
				cout << setw(18) << "查找书籍" << "|";
				cout << setw(18) << "全馆图书借阅情况" << "|";
				cout << setw(18) << "查询学生借阅情况" << "|";
				cout << setw(18) << "修改密码" << "|" << endl;
				cout << nStart(115) << endl;

				cout << "输入：";
				cin >> select;
				cout << "\n\n";
				/*判断输入是否合法*/
				switch (select) {
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					contin = 0;
					break;
				default:
					cout << "\n";
					cout << "输入非法，请重新输入" << endl;
					contin++;
				}
			}

			//退出本循环的条件
			if (contin == 0) {//不必重复判断用户操作，退出循环
				break;
			}
			else if (contin == 5) {
				cout << "错误次数过多，程序退出终止" << endl;
				return 0;
			}
		}


		//运行到这里，用户已经做好了合法选择
		//以下是各类操作细节
		//读者借书
		if (identity == 1 && select == 1) {
			//用户搜寻书籍信息后保存对应书籍的下标号，用户只能借阅这些下标号对应的书，错误借阅。
			cout << "请输入你需要借阅的书籍信息：";
			cin >> strtemp[0];
			cout << nStart(115) << endl;
			lib.searchBook(strtemp[0]);
			cout << nStart(115) << endl;
			cout << "请输入你需要借阅的图书编号：";
			cin >> inttemp[0]; //用户的输入
			cout << "\n";
			s[stupos].borrowBook(lib, inttemp[0]);  //调用学生用户借书函数
			cout << "\n\n";
		}

		else if (identity == 1 && select == 2) {  //读者还书
			cout << "**********************************************您的个人信息和借阅信息如下*******************************************" << endl;
			s[stupos].showInfo();
			cout << nStart(115) << endl;
			if (s[stupos].getPos() != 0) {//学生有借书
				cout << "请选择您要归还的图书编号：";
				cin >> inttemp[0];
				s[stupos].returnBook(lib, inttemp[0]);
				//cout << nStart(70) << endl;
			}
			cout << "\n\n";
		}


		//读者查看自己的借阅信息
		else if (identity == 1 && select == 3) {  
			cout << "**********************************************您的个人信息和借阅信息如下*******************************************" << endl;
			s[stupos].showInfo();
			cout << nStart(115) << endl;
			cout << "\n\n";
		}


		//读者或者图书管理员查找书籍信息
		else if ((identity == 1 && select == 4)||(identity == 2 && select == 3)) {   
			cout << "请输入您要查找的书籍信息：";
			cin >> strtemp[0];
			cout << nStart(120) << endl;
			lib.searchBook(strtemp[0]);
			cout << nStart(120) << endl;
			cout << "\n\n";
		}

		//读者修改密码
		else if (identity == 1 && select == 6) {
			cout << "请输入您当前的密码：";
			cin >> strtemp[0];
			cout << "请输入新密码：";
			cin >> strtemp[1];
			s[stupos].changePassword(strtemp[0], strtemp[1]);
			cout << "\n\n";
		}

		//图书管理员录入书籍
		else if ((identity == 2 && select == 1)){
			cout << "欢迎进入书籍录入系统"<<endl;
			cout << "请输入书籍名称：";
			cin >> strtemp[0];
			cout << "请输入书籍作者：";
			cin >> strtemp[1];
			cout << "请输入书籍ISBN：";
			cin >> strtemp[2];
			cout << "请输入书籍出版社：";
			cin >> strtemp[3];
			cout << "请输入书籍数量：";
			cin >> inttemp[0];
			lib.addBook(strtemp[0], strtemp[1], strtemp[2], strtemp[3],inttemp[0]);
			cout << "书籍《"<< strtemp[0]<<"》录入成功" << endl;
			cout << "\n\n";
		}
		//图书管理员查看当前图书列表，学生也可以查看当前图书列表
		else if ((identity == 2 && select == 2)||(identity == 1 && select == 5)) { 
			lib.showBookList();
			cout << "\n\n";
		}

		//图书管理员查看图书借阅情况 
		else if (identity == 2 && select == 4) {  
			lib.showLibInfo();
			cout << "\n\n";
		}

		//图书管理员查询某个学生的借阅情况
		else if (identity == 2 && select == 5) {  
			cout << "请输入您要查找的学生学号:";
			cin >> strtemp[0];

			int i;
			for (i = 0; i < STUDENT_NUM; i++) {
				if (s[i].getID() == strtemp[0]) { //找到该学生
					s[i].showInfo();              //显示借阅信息
					break;
				}

			}
			if (i == STUDENT_NUM) {  //查找了所有学生
				cout << "查无此生" << endl;
			}
			cout << "\n\n";
		}

		//图书管理员修改密码
		else if (identity == 2 && select == 6) {  
			cout << "请输入您当前的密码：";
			cin >> strtemp[0];
			cout << "请输入新密码：";
			cin >> strtemp[1];
			lib.changePassword(strtemp[0], strtemp[1]);
			cout << "\n\n";
		}

	}

	return 0;
	
}


