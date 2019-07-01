//�ļ����ƣ�userdata.h
//ժ    Ҫ���û������������
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28
#ifndef _USERDATA_H_
#define _USERDATA_H_

#include "fileproc.h"
#include "custom_func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

class userdata:public fileproc  //�û����� ������
{
	public:
		userdata() { }
		userdata(const char *filename) {
			this->filename=filename;
		}

		void search(); //��������
		void createProfile(); //����������Ա��
		void manageID(); //�û�ID����
		void manageProfile(int targetid); //�޸��û���������

		void showData() const { //��ʾ�û���Ϣ
			cout<<t.id<<'\t'<<t.name<<'\t'<<(banned ? 'Y' : 'N')<<endl;
		}
		void readData(fstream &f) { //��ȡ�û���Ϣ
			banned=f.get();
			firstlogin=f.get();
			f.read((char *)&t,sizeof(temp_data));
			f.get();
		}
		void writeData(fstream &f) { //д���û���Ϣ
			f.put(banned);
			f.put(firstlogin);
			f.write((char *)&t,sizeof(temp_data));
			f<<endl;
		}

		//��ʱ����
		bool banned; //������״̬��false��ʾ��
		bool firstlogin; //ʹ��״̬��true��ʾ����ʹ�ô�ע��
		struct temp_data {
			char name[30]; //�û���
			char pwd[30]; //�û�����
			int id; //�û�id����Ӧ��־ϵͳ�ļ���
		} t;
};

#endif
