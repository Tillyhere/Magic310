//�ļ����ƣ�custom_func.cpp
//ժ    Ҫ���Զ��庯����ʵ�֣���������������ܡ���ȡʱ���
//��ǰ�汾��0.0
//��    �ߣ������
//������ڣ�2019.6.30
//ȡ���汾��NULL
//ԭ �� �ߣ�NULL
//������ڣ�NULL
#include "custom_func.h"

void inputPWD(char *pwd,int maxLength) //���ط�ʽ��������
{
	int i;
	for(i=0; i<maxLength; i++) {
		if((pwd[i]=getch())=='\r') {
			break;
		}
		if(pwd[i]==8) {
			if(i==0) { //����ĸ�ظ�������
				i--;
			}
			if(i>0) { //������ĸ�ظ�ɾ��i-1���ַ�
				i-=2;
				cout<<'\b'<<' '<<'\b';
			}
			continue;
		}
		cout<<'*';
	}
	pwd[i]='\0';
}

void encryptPWD(char *pwd,int key) //�ִ������ܣ�pwdΪ�����ַ�����keyΪ����˽Կ 
{
	for(int i=0; pwd[i]!='\0'; i++) {
		pwd[i]=(char)(pwd[i]^key);
	}
}

string getCurrentTimeStr() //��ȡ��ǰʱ���ַ���
{
	time_t t = time(0);
	char timestr[20] = {0};
	strftime(timestr,sizeof(timestr),"%Y-%m-%d %H:%M:%S",localtime(&t)); //��-��-�� ʱ-��-��
	return timestr;
}
