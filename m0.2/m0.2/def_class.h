//文件名称：def_class.h
//摘    要：影碟数据、用户数据类的声明
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28
#ifndef _DEF_CLASS_H
#define _DEF_CLASS _H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class fileprco  //文件处理基类
{
	public:
		fileprco() { }
		fileprco(const char *filename) {
			this->filename=filename;
		}
		void setfile(const char *filename) {
			this->filename=filename;
		}
		void checkfile() { //检查文件读写权限
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

		virtual void showdata() const =0;
		virtual void readdata(fstream &f) =0;
		virtual void writedata(fstream &f) =0;
	protected:
		const char *filename; //文件名
};

class viddata:public fileprco  //影碟数据 处理类
{
	public:
		viddata() { }
		viddata(const char *filename) {
			this->filename=filename;
		}

		void search(); //搜索数据
		void add(); //添加数据
		void del(); //删除数据
		void rec(); //恢复数据
		void update(); //更新数据
		void in(); //归还影碟
		void out(); //租出影碟
		void rebuiltfile(); //重组数据文件

		void showdata() const { //显临时信息
			cout<<t.id<<'\t'<<t.name<<'\t'<<t.num_in<<'\t'<<t.num_out<<endl;
		}
		void readdata(fstream &f) { //读取一条数据至数据组
			state=f.get();
			f.read((char *)&t,sizeof(short)*2);
			f>>t.id>>t.name;
			f.get(); //取掉endl换行符
		}
		void writedata(fstream &f) { //将临时数据写入文件
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

class userdata:public fileprco  //用户数据 处理类
{
	public:
		userdata() { }
		userdata(const char *filename) {
			this->filename=filename;
		}
		
		void creatprofile(); //创建用户档案文件 
		void ban(); //拉黑用户 
		void unban(); //解除拉黑 
		void changename(); //修改用户名 
		void changepwd(); //修改密码 
		
		void showdata() const{ //显示用户信息 
			cout<<t.id<<'\t'<<t.name<<'\t'<<(blacklist ? 'y' : 'n')<<endl;
		} 
		void readdata(fstream &f){ //读取用户信息 
			blacklist=f.get();
			firstlogin=f.get();
			f.read((char *)&t,sizeof(temp_data));
			f.get();
		} 
		void writedata(fstream &f){ //写入用户信息 
			f.put(blacklist);
			f.put(firstlogin);
			f.write((char *)&t,sizeof(temp_data));
			f<<endl;
		} 
		
		//临时数据总大小
		bool blacklist; //黑名单状态，false表示否 
		bool firstlogin; //首次登录状态，true表示首次登录 
		struct temp_data {
			int id; //用户id即对应日志系统文件名 
			char name[30]; //用户名
			char pwd[30]; //用户密码
		} t;
};

#endif
