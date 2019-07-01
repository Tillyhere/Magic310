//�ļ����ƣ�viddata.h
//ժ    Ҫ��Ӱ�����ݵ�����
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28
#ifndef _VIDDATA_H_
#define _VIDDATA_H_

#include "fileproc.h"
#include "custom_func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

class viddata:public fileproc//Ӱ������ ������
{
	public:
		viddata() { }
		viddata(const char *filename) {
			this->filename=filename;
		}

		void search(); //��������
		void add(); //�������
		void vidDelRec(); //ɾ��/�ָ�����
		void update(); //��������
		void vidInOut(const int userid,const char *username); //�黹/���Ӱ��
		void rebuiltFile(); //���������ļ�

		void showData() const { //����ʱ��Ϣ
			cout<<t.id<<'\t'<<t.name<<'\t'<<t.num_in<<'\t'<<t.num_out<<(state ? 'N' : 'Y')<<endl;
		}
		void readData(fstream &f) { //��ȡһ��������������
			state=f.get();
			f.read((char *)&t,sizeof(short)*2);
			f>>t.id>>t.name;
			f.get(); //ȡ��endl���з�
		}
		void writeData(fstream &f) { //����ʱ����д���ļ�
			f.put(state);
			f.write((char *)&t,sizeof(short)*2);
			f<<t.id<<'\t'<<t.name<<endl;
		}

		//��¼һ����ʱ���ݵ�������
		bool state; //ɾ��״̬��false��ʾɾ��
		struct temp_data {
			short num_in; //����
			short num_out; //�����
			string id; //Ӱ��id
			string name; //Ӱ����
		} t;
};

#endif
