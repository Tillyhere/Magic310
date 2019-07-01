//文件名称：custom_func.h
//摘    要：自定义函数的声明，如密码输入与加密、获取时间等
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28
#ifndef _CUSTOM_FUNC_H_
#define _CUSTOM_FUNC_H_

#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
using namespace std;

void inputPWD(char *pwd,int maxLength); //隐藏方式输入密码

void encryptPWD(char *pwd,int key); //加密密码

string getCurrentTimeStr(); //获取当前时间字符串

#endif
