//�ļ����ƣ�custom_func.h
//ժ    Ҫ���Զ��庯������������������������ܡ���ȡʱ���
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28
#ifndef _CUSTOM_FUNC_H_
#define _CUSTOM_FUNC_H_

#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
using namespace std;

void inputPWD(char *pwd,int maxLength); //���ط�ʽ��������

void encryptPWD(char *pwd,int key); //��������

string getCurrentTimeStr(); //��ȡ��ǰʱ���ַ���

#endif
