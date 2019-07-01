//文件名称：viddatd.cpp
//摘    要：viddata类的实现
//当前版本：0.1
//作    者：杨彦军
//完成日期：2019.6.30
//取代版本：0.0
//原 作 者：杨彦军
//完成日期：2019.6.29

#include "userdata.h"

void userdata::search()
{
	cout<<"~查询用户"<<endl;
	fstream f(filename,ios::in|ios::binary);
	do {
		cout<<"1.ID查询 2.用户名查询 else.返回主菜单 :";
		int targetid=0;
		cin>>targetid;
		if(targetid==1) {
			cout<<"\t请输入用户ID :";
			cin>>targetid;
			f.seekg((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
			readData(f);
			cout<<"\nID\t用户名\t\t黑名单状态"<<endl;
			showData();
		} else if(targetid==2) {
			string sample;
			string matchsample;
			f.seekg(0);
			cout<<"\t请输入用户名关键字 :";
			cin>>matchsample;
			cout<<"\nID\t用户名\t\t黑名单状态"<<endl;
			readData(f);
			do { //开始遍历文件
				sample=t.name;
				if((sample.find(matchsample))!=string::npos) { //关键字匹配
					showData();
				}
				readData(f);
			} while(!f.eof());
			f.clear();
		}
		cout<<"_________________________搜索结束"<<endl;
		cout<<"\n1.继续查询 else.返回主菜单 :";
		cin.ignore(1024,'\n');
	} while(cin.get()=='1');
	f.close();
}

void userdata::createProfile()
{
	cout<<"~创建会员卡"<<endl;
	cout<<"提示：1.第一次创建时，id段起始数请输入0，用户id从0开始\n"
	    <<"      2.创建新id段会覆盖原id段信息（姓名、密码及租借记录）。可用于覆盖原用户信息。"<<endl;
	cout<<"1.开始创建 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		banned=false;
		firstlogin=true;
		int startid=0,endid=0;
		do {
			cout<<"\t请输入id段的起始数 终止数 :" ;
			cin>>startid>>endid;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________警告：输入了错误信息！"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //重新输入
			} else {
				f.seekp((int)(startid*(2+sizeof(userdata::temp_data)+1)));
				char logfilename[28]= {0};
				for(t.id=startid; t.id<=endid; t.id++) {
					writeData(f);
					sprintf(logfilename,"./datas/userdatas/%d.csv",t.id);
					fstream f_log(logfilename,ios::out); //创建租借记录文件
					f_log<<"时间"<<','<<"用户名"<<','<<"用户ID"<<','<<"租出/归还"<<','<<"影片名"<<','<<"影片ID"<<endl;
					f_log.close();
				}

				cout<<"_________________________创建id段"<<startid<<"至"<<endid<<"成功";
				sleep(1);
				break;
			}
		} while(1);
		f.close();
	}
}

void userdata::manageID()
{
	cout<<"~用户ID管理"<<endl;
	cout<<"提示：\t1.拉黑用户ID将拒绝该用户登录系统，但保留ID租借信息。"<<endl
	    <<"\t2.解封用户ID将恢复被拉黑用户的权限，但无法恢复被回收的数据。"<<endl
	    <<"\t3.回收用户ID将彻底删除该ID的用户信息和租借记录,ID重置为未注册状态。"<<endl;
	cout<<"1.输入ID else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		int targetid=0;
		do {
			cout<<"\t请输入目标用户ID :" ;
			cin>>targetid;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________警告：输入了错误信息！"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //重新输入
			} else {
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				readData(f);
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				cout<<"\n用户ID:\t"<<t.id
				    <<"\n用户名:\t"<<t.name<<endl;
				cout<<"1.解封该ID 2.拉黑并回收ID 3.仅拉黑该ID else.取消操作 :";
				cin.ignore(1024,'\n');
				char logfilename[28]= {0};
				switch(cin.get()) {
					case '2':
						sprintf(logfilename,"./datas/userdatas/%d.csv",targetid);
						if(remove(logfilename)) { //若删除失败
							cout<<"\n权限异常，请手动删除"<<logfilename<<"租借记录文件"<<endl;
						}
						f.put(true); // firstlogin=true
					case '3':
						f.put(true); // banned=true
						break;
					case '1':
						f.put(false); // banned=false
						break;
				}

				cout<<"_________________________操作成功";
				sleep(1);
				break;
			}
		} while(1);
		f.close();
	}
}

void userdata::manageProfile(int targetid)  //客户端管理员端共有函数
{
	/*cout<<"~用户信息管理"<<endl; //这部分函数写进管理员端主函数
	cout<<"提示：\t用于帮助用户找回密码。"<<endl
	cout<<"1.输入ID else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		int targetid=0;
		do {
			cout<<"\t请输入目标用户ID :" ;
			cin>>targetid;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________警告：输入了错误信息！"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //重新输入
			} else {
				usr.manageprofile(targetid);
			｝
		} while(1);
	}*/
	fstream f(this->filename,ios::in|ios::out|ios::binary);
	f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
	readData(f);
	cout<<"\n用户ID:\t"<<t.id
	    <<"\n用户名:\t"<<t.name<<endl;
	cout<<"1.确认修改此ID else.取消操作 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)+1)); //这里不关心banned位
		f.put(false); // firstlogin=true
		cout<<"\n请输入信息(首字符输入\'%\'表示不做更改)"<<endl;
		cout<<"用户名:";
		cin.ignore(1024,'\n');
		cin.get(t.name,30);
		if(t.name[0]=='%') {
			f.seekp(30,ios::cur); //指针跳过用户名
		} else {
			f.write((char *)&t.name,30); //写入新用户名
		}
		do {
			cout<<"用户密码:";
			inputPWD(t.pwd,30);
			if(t.pwd[0]=='%') {
				break;
			} else {
				cout<<"\t确认密码:";
				char pwdcheck[30]= {0};
				inputPWD(pwdcheck,30);
				if(strcmp(pwdcheck,t.pwd)) {
					cout<<"\t输入密码不一致!"<<'\r';
					continue;
				}
				encryptPWD(t.pwd,targetid); //密码加密
			}
		} while(false);
		f.write((char *)&t.pwd,30); //写入新密码
		cout<<"\n_________________________操作成功";
	}
	f.close();
}


