//�ļ����ƣ�main.cpp
//ժ    Ҫ��������
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28

#include "fileproc.h"
#include "viddata.h"
#include "userdata.h"
#include "custom_func.h"
using namespace std;

int main() {
	viddata vid("./datas/data_video");
	vid.checkFile();
	userdata usr("./datas/data_user");
	usr.checkFile();


	//usr.createProfile();
	//vid.vidInOut(1,"testname");

	//usr.manageID();
	//usr.search();
	//usr.manageProfile(1);

	cout<<"********************************\n"
	    <<"����ӭʹ��ĳ������ڲ������ߣ�\n"
	    <<"******************************** \t���»س���ʼʹ��";
	do {
		cin.clear(); //�Է��û������߰����������cin��
		cin.ignore(1024,'\n');
		system("cls");
		cout<<"***********************************************\n"
		    <<"��1.����Ӱ�� 2.����Ӱ�� 3.��ѯӰ�� 4.ɾ��Ӱ����\n"
		    <<"��5.���/�黹Ӱ�� 6.Ӱ�� 7.�����ļ� other.�˳���\n"
		    <<"*********************************************** :";
		switch(cin.get()) { //�ڶ��֧������£�switch case��if else����Ч
			case '1':
				vid.add();
				break;
			case '2':
				vid.update();
				break;
			case '3':
				vid.search();
				break;
			case '4':
				vid.vidDelRec();
				break;
			case '5':
				vid.vidInOut(0,"Administrator");
				break;
			case '6':
				//vid.in();
				break;
			case '7':
				vid.rebuiltFile();
				break;
			case '8':
				//vid.rec();
				break;
			default:
				return 0;
		}
	} while(true); //�ص����˵�*/
	return 0;
}

