//�ļ����ƣ�def_class.h
//ժ    Ҫ��Ӱ�����ݡ��û������������
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28
#ifndef _DEF_CLASS_H
#define _DEF_CLASS _H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class fileprco  //�ļ��������
{
	public:
		fileprco() { }
		fileprco(const char *filename) {
			this->filename=filename;
		}
		void setfile(const char *filename) {
			this->filename=filename;
		}
		void checkfile() { //����ļ���дȨ��
			ifstream f(filename);
			if(f.fail()) {
				f.close();
				ofstream fnew(filename);
				if(fnew.fail()) {
					cout<<"�ļ�����ʧ�ܣ��˳�����"<<endl;
					cin.get();  
					exit(100);
				}
			}
			f.close();
		}
		//virtual void rebuiltfile() =0;

		virtual void showdata() const =0;
		virtual void readdata(fstream &f) =0;
		virtual void writedata(fstream &f) =0;
	protected:
		const char *filename; //�ļ���
};

class viddata:public fileprco  //Ӱ������ ������
{
	public:
		viddata() { }
		viddata(const char *filename) {
			this->filename=filename;
		}

		void search(); //��������
		void add(); //�������
		void del(); //ɾ������
		void rec(); //�ָ�����
		void update(); //��������
		void in(); //�黹Ӱ��
		void out(); //���Ӱ��
		void rebuiltfile(); //���������ļ�

		void showdata() const { //����ʱ��Ϣ
			cout<<t.id<<'\t'<<t.name<<'\t'<<t.num_in<<'\t'<<t.num_out<<endl;
		}
		void readdata(fstream &f) { //��ȡһ��������������
			state=f.get();
			f.read((char *)&t,sizeof(short)*2);
			f>>t.id>>t.name;
			f.get(); //ȡ��endl���з�
		}
		void writedata(fstream &f) { //����ʱ����д���ļ�
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

class userdata:public fileprco  //�û����� ������
{
	public:
		userdata() { }
		userdata(const char *filename) {
			this->filename=filename;
		}
		
		void creatprofile(); //�����û������ļ� 
		void ban(); //�����û� 
		void unban(); //������� 
		void changename(); //�޸��û��� 
		void changepwd(); //�޸����� 
		
		void showdata() const{ //��ʾ�û���Ϣ 
			cout<<t.id<<'\t'<<t.name<<'\t'<<(blacklist ? 'y' : 'n')<<endl;
		} 
		void readdata(fstream &f){ //��ȡ�û���Ϣ 
			blacklist=f.get();
			firstlogin=f.get();
			f.read((char *)&t,sizeof(temp_data));
			f.get();
		} 
		void writedata(fstream &f){ //д���û���Ϣ 
			f.put(blacklist);
			f.put(firstlogin);
			f.write((char *)&t,sizeof(temp_data));
			f<<endl;
		} 
		
		//��ʱ�����ܴ�С
		bool blacklist; //������״̬��false��ʾ�� 
		bool firstlogin; //�״ε�¼״̬��true��ʾ�״ε�¼ 
		struct temp_data {
			int id; //�û�id����Ӧ��־ϵͳ�ļ��� 
			char name[30]; //�û���
			char pwd[30]; //�û�����
		} t;
};

#endif
