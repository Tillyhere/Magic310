//文件名称：userdata.h
//摘    要：用户数据类的声明
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28
#ifndef _USERDATA_H_
#define _USERDATA_H_

#include "fileproc.h"
#include "custom_func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

class userdata:public fileproc  //用户数据 处理类
{
	public:
		userdata() { }
		userdata(const char *filename) {
			this->filename=filename;
		}

		void search(); //搜索数据
		void createProfile(); //创建创建会员卡
		void manageID(); //用户ID管理
		void manageProfile(int targetid); //修改用户名和密码

		void showData() const { //显示用户信息
			cout<<t.id<<'\t'<<t.name<<'\t'<<(banned ? 'Y' : 'N')<<endl;
		}
		void readData(fstream &f) { //读取用户信息
			banned=f.get();
			firstlogin=f.get();
			f.read((char *)&t,sizeof(temp_data));
			f.get();
		}
		void writeData(fstream &f) { //写入用户信息
			f.put(banned);
			f.put(firstlogin);
			f.write((char *)&t,sizeof(temp_data));
			f<<endl;
		}

		//临时数据
		bool banned; //黑名单状态，false表示否
		bool firstlogin; //使用状态，true表示无人使用待注册
		struct temp_data {
			char name[30]; //用户名
			char pwd[30]; //用户密码
			int id; //用户id即对应日志系统文件名
		} t;
};

#endif
