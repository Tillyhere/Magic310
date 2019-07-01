//文件名称：custom_func.cpp
//摘    要：自定义函数的实现，如密码输入与加密、获取时间等
//当前版本：0.0
//作    者：杨彦军
//完成日期：2019.6.30
//取代版本：NULL
//原 作 者：NULL
//完成日期：NULL
#include "custom_func.h"

void inputPWD(char *pwd,int maxLength) //隐藏方式输入密码
{
	int i;
	for(i=0; i<maxLength; i++) {
		if((pwd[i]=getch())=='\r') {
			break;
		}
		if(pwd[i]==8) {
			if(i==0) { //首字母回格则跳过
				i--;
			}
			if(i>0) { //非首字母回格删除i-1的字符
				i-=2;
				cout<<'\b'<<' '<<'\b';
			}
			continue;
		}
		cout<<'*';
	}
	pwd[i]='\0';
}

void encryptPWD(char *pwd,int key) //字串符加密，pwd为加密字符串，key为加密私钥 
{
	for(int i=0; pwd[i]!='\0'; i++) {
		pwd[i]=(char)(pwd[i]^key);
	}
}

string getCurrentTimeStr() //获取当前时间字符串
{
	time_t t = time(0);
	char timestr[20] = {0};
	strftime(timestr,sizeof(timestr),"%Y-%m-%d %H:%M:%S",localtime(&t)); //年-月-日 时-分-秒
	return timestr;
}
