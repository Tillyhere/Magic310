//文件名称：fileproc.h
//摘    要：影碟数据、用户数据类的基类声明
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28
#ifndef _FILEPROC_H_
#define _FILEPROC_H_

#include <iostream>
#include <fstream>
using namespace std;

class fileproc  //文件处理基类
{
	public:
		fileproc() { }
		fileproc(const char *filename) {
			this->filename=filename;
		}
		void setFile(const char *filename) {
			this->filename=filename;
		}
		void checkFile() { //检查文件读写权限
			ifstream f(filename);
			if(f.fail()) {
				f.close();
				ofstream fnew(filename);
				if(fnew.fail()) {
					cout<<"文件创建失败，退出程序。"<<endl;
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
		const char *filename; //欲处理文件文件名
};

#endif
