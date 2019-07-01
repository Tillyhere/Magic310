//文件名称：main.cpp
//摘    要：主程序
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28

#include "fileproc.h"
#include "viddata.h"
#include "userdata.h"
#include "custom_func.h"
using namespace std;

int main() {
	viddata vid("./datas/data_video");
	vid.checkFile();
	userdata usr("./datas/data_user");
	usr.checkFile();


	//usr.createProfile();
	//vid.vidInOut(1,"testname");

	//usr.manageID();
	//usr.search();
	//usr.manageProfile(1);

	cout<<"********************************\n"
	    <<"｜欢迎使用某音像店内部管理工具｜\n"
	    <<"******************************** \t按下回车开始使用";
	do {
		cin.clear(); //以防用户用乱七八糟的招数损坏cin流
		cin.ignore(1024,'\n');
		system("cls");
		cout<<"***********************************************\n"
		    <<"｜1.增加影碟 2.更新影碟 3.查询影碟 4.删除影碟｜\n"
		    <<"｜5.租出/归还影碟 6.影碟 7.重组文件 other.退出｜\n"
		    <<"*********************************************** :";
		switch(cin.get()) { //在多分支的情况下，switch case比if else更高效
			case '1':
				vid.add();
				break;
			case '2':
				vid.update();
				break;
			case '3':
				vid.search();
				break;
			case '4':
				vid.vidDelRec();
				break;
			case '5':
				vid.vidInOut(0,"Administrator");
				break;
			case '6':
				//vid.in();
				break;
			case '7':
				vid.rebuiltFile();
				break;
			case '8':
				//vid.rec();
				break;
			default:
				return 0;
		}
	} while(true); //回到主菜单*/
	return 0;
}

