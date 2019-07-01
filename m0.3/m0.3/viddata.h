//文件名称：viddata.h
//摘    要：影碟数据的声明
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28
#ifndef _VIDDATA_H_
#define _VIDDATA_H_

#include "fileproc.h"
#include "custom_func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

class viddata:public fileproc//影碟数据 处理类
{
	public:
		viddata() { }
		viddata(const char *filename) {
			this->filename=filename;
		}

		void search(); //搜索数据
		void add(); //添加数据
		void vidDelRec(); //删除/恢复数据
		void update(); //更新数据
		void vidInOut(const int userid,const char *username); //归还/租出影碟
		void rebuiltFile(); //重组数据文件

		void showData() const { //显临时信息
			cout<<t.id<<'\t'<<t.name<<'\t'<<t.num_in<<'\t'<<t.num_out<<(state ? 'N' : 'Y')<<endl;
		}
		void readData(fstream &f) { //读取一条数据至数据组
			state=f.get();
			f.read((char *)&t,sizeof(short)*2);
			f>>t.id>>t.name;
			f.get(); //取掉endl换行符
		}
		void writeData(fstream &f) { //将临时数据写入文件
			f.put(state);
			f.write((char *)&t,sizeof(short)*2);
			f<<t.id<<'\t'<<t.name<<endl;
		}

		//记录一条临时数据的数据组
		bool state; //删除状态，false表示删除
		struct temp_data {
			short num_in; //余量
			short num_out; //租出量
			string id; //影碟id
			string name; //影碟名
		} t;
};

#endif
