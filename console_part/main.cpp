//�ļ����ƣ�main.cpp
//ժ    Ҫ��������
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28
#include "def_class.h"

int main()
{
	viddata vid("./datas/data_video");
	vid.checkfile();
	userdata usr("./datas/data_user");
	usr.checkfile();
	int targetid;
	//usr.createProfile();
	//usr.manageID(); 
	//usr.manageProfile(1);
	
	cout<<"********************************\n"
	    <<"����ӭʹ��Ӱ���Ӱ�����ϵͳ��\n"
	    <<"******************************** \t���»س���ʼʹ��";
L0:	cin.clear(); //�Է��û������߰����������cin��
	cin.ignore(1024,'\n');
	system("cls");
	cout<<"***********************************************\n"
	    <<"��1.ע���˻� 2.��¼ϵͳ other.�˳���\n"
	    <<"*********************************************** :";
	switch(cin.get()) { //�ڶ��֧������£�switch case��if else����Ч
		case '1':
			usr.manageProfile(targetid);
			break;
		case '2':
			usr.login(targetid);
			break;		
		default:
			return 0;
	}
	goto L0; //�ص����˵�
	return 0;
}

