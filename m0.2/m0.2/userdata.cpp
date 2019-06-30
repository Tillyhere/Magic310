//文件名称：viddatd.cpp
//摘    要：viddata类的实现
//当前版本：0.0
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：NULL
//原 作 者：NULL
//完成日期：NULL

#include "def_class.h"

void userdata::creatprofile(){
	cout<<"~创建会员卡"<<endl;
	cout<<"警告：第一次创建时，id段起始数请输入0，创建新id段会覆盖原id段信息！"<<endl;
	cout<<"1.开始创建 else.返回主菜单 :";
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
		//strcpy(t.pwd,"pwd123456"); //默认密码123456 
		int startid=0,endid=0; 
		do { 
			cout<<"\t请输入id段的起始数 终止数 :" ;
			cin>>startid>>endid;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________警告：输入了错误信息！";
				cin.clear();
				continue; //重新输入
			} else {
				f.seekp((int)(startid*(2+sizeof(userdata::temp_data)+1)));
				for(t.id=startid;t.id<=endid;t.id++){
					writedata(f);
				}
				cout<<"_________________________创建id段"<<startid<<'-'<<endid<<"成功"<<endl; 
			}
		} while(cin.get()=='1');
		f.close();
	}
}
