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
	
	usr.creatprofile(); 
	
	
/*	cout<<"********************************\n"
	    <<"����ӭʹ��ĳ������ڲ������ߣ�\n"
	    <<"******************************** \t���»س���ʼʹ��";
L0:	cin.clear(); //�Է��û������߰����������cin��
	cin.ignore(1024,'\n');
	system("cls");
	cout<<"***********************************************\n"
	    <<"��1.�������� 2.�������� 3.��ѯ���� 4.ɾ�����ݣ�\n"
	    <<"��5.���Ӱ�� 6.�黹Ӱ�� 7.�����ļ� other.�˳���\n"
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
			vid.del();
			break;
		case '5':
			vid.out();
			break;
		case '6':
			vid.in();
			break;
		case '7':
			vid.rebuiltfile();
			break;
		case '8':
			vid.rec();
			break;
		default:
			return 0;
	}
	goto L0; //�ص����˵�*/
	return 0;
}

