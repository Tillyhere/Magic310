//�ļ����ƣ�viddatd.cpp
//ժ    Ҫ��viddata���ʵ��
//��ǰ�汾��0.0
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��NULL
//ԭ �� �ߣ�NULL
//������ڣ�NULL

#include "def_class.h"

void userdata::creatprofile(){
	cout<<"~������Ա��"<<endl;
	cout<<"���棺��һ�δ���ʱ��id����ʼ��������0��������id�λḲ��ԭid����Ϣ��"<<endl;
	cout<<"1.��ʼ���� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::out);
		//fstream f(filename,ios::out|ios::binary);
		blacklist=false;
		firstlogin=true;
		string name="empty name";
		string pwd="123456";
		name.copy(t.name,30);
		//strcpy(t.name,"nameemptyname");
		//strcpy(t.pwd,"pwd123456"); //Ĭ������123456 
		int startid=0,endid=0; 
		do { 
			cout<<"\t������id�ε���ʼ�� ��ֹ�� :" ;
			cin>>startid>>endid;
			if(cin.fail()) { //�������������Ⱦ�ļ�
				cout<<"_________________________���棺�����˴�����Ϣ��";
				cin.clear();
				continue; //��������
			} else {
				f.seekp((int)(startid*(2+sizeof(userdata::temp_data)+1)));
				for(t.id=startid;t.id<=endid;t.id++){
					writedata(f);
				}
				cout<<"_________________________����id��"<<startid<<'-'<<endid<<"�ɹ�"<<endl; 
			}
		} while(cin.get()=='1');
		f.close();
	}
}
