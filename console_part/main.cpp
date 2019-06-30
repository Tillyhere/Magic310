//文件名称：main.cpp
//摘    要：主程序
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28
#include "def_class.h"

int main()
{
	viddata vid("./datas/data_video");
	vid.checkfile();
	userdata usr("./datas/data_user");
	usr.checkfile();
	int targetid;
	//usr.createProfile();
	//usr.manageID(); 
	//usr.manageProfile(1);
	
	cout<<"********************************\n"
	    <<"｜欢迎使用影像店影碟租借系统｜\n"
	    <<"******************************** \t按下回车开始使用";
L0:	cin.clear(); //以防用户用乱七八糟的招数损坏cin流
	cin.ignore(1024,'\n');
	system("cls");
	cout<<"***********************************************\n"
	    <<"｜1.注册账户 2.登录系统 other.退出｜\n"
	    <<"*********************************************** :";
	switch(cin.get()) { //在多分支的情况下，switch case比if else更高效
		case '1':
			usr.manageProfile(targetid);
			break;
		case '2':
			usr.login(targetid);
			break;		
		default:
			return 0;
	}
	goto L0; //回到主菜单
	return 0;
}

