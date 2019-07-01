//�ļ����ƣ�fileproc.h
//ժ    Ҫ��Ӱ�����ݡ��û�������Ļ�������
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28
#ifndef _FILEPROC_H_
#define _FILEPROC_H_

#include <iostream>
#include <fstream>
using namespace std;

class fileproc  //�ļ��������
{
	public:
		fileproc() { }
		fileproc(const char *filename) {
			this->filename=filename;
		}
		void setFile(const char *filename) {
			this->filename=filename;
		}
		void checkFile() { //����ļ���дȨ��
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

		virtual void showData() const =0;
		virtual void readData(fstream &f) =0;
		virtual void writeData(fstream &f) =0;
	protected:
		const char *filename; //�������ļ��ļ���
};

#endif
