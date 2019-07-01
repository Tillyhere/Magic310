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
	cout<<"~Query User Information"<<endl;
	fstream f(filename,ios::in|ios::binary);
	do {
		cout<<"1.ID Query 2.Username Query else.return menu :";
		int targetid=0;
		cin>>targetid;
		if(targetid==1) {
			cout<<"\t Plesae input user's ID :";
			cin>>targetid;
			f.seekg((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
			readData(f);
			cout<<"\nID\tUsername\t\tBlacklist"<<endl;
			showData();
		} else if(targetid==2) {
			string sample;
			string matchsample;
			f.seekg(0);
			cout<<"\tPlease input username's keywords";
			cin>>matchsample;
			cout<<"\nID\tUsername\t\tBlacklist"<<endl;
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
		cout<<"_________________________Query End"<<endl;
		cin.ignore(1024,'\n');
		cout<<"\n1.Continue else.Return menu :";
	} while(cin.get()=='1');
	f.close();
}

void userdata::createProfile()
{
	cout<<"~Membership Card Transaction"<<endl;
	cout<<"Tips：1.When it is first created，Please input 0 into the starting number of ID segment\n"
	
	    <<"      2.Creat new ID segment will cover the old information（name,passwords and rental record)."<<endl;
	cout<<"1.Get started else.Return menu:";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		banned=false;
		firstlogin=true;
		int startid=0,endid=0;
		do {
			cout<<"\tPlease input the starting number and ending number of ID segment" ;
			cin>>startid>>endid;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________Warning:Wrong Information was enterd"<<endl;
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
					f_log<<"Datetime"<<','<<"Username"<<','<<"User'ID"<<','<<"Rent/Return"<<','<<"Movie's name'"<<','<<"Movie's ID"<<endl;
					f_log.close();
				}

				cout<<"_________________________Creat the segment of ID"<<startid<<"to"<<endid<<"successfully";
				sleep(1);
				break;
			}
		} while(1);
		f.close();
	}
}

void userdata::manageID()
{
	cout<<"~ID Management"<<endl;
	cout<<"T：\t1.Block the user'ID:Access permission will be cancelled,while information of the ID will be remained."<<endl
	    <<"\t2.Unblocek the ID:The authority will be recoverd,recycled data irreparable."<<endl
	    <<"\t3.Recycle the ID:Delete the ID's information and rental record completely.Reset it back to its initial state"<<endl;
	cout<<"1.Input ID else.return menu:";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		int targetid=0;
		do {
			cout<<"\tPlease input target users'ID :" ;
			cin>>targetid;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________Warning:wrong information was entered"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //重新输入
			} else {
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				readData(f);
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				cout<<"\n用户ID:\t"<<t.id
				    <<"\n用户名:\t"<<t.name<<endl;
				cout<<"1.Unblock the ID 2.Block and recycle the ID 3.Block the ID only else.Cancel:";
				cin.ignore(1024,'\n');
				char logfilename[28]= {0};
				switch(cin.get()) {
					case '2':
						sprintf(logfilename,"./datas/userdatas/%d.csv",targetid);
						if(remove(logfilename)) { //若删除失败
							cout<<"\nAbnormal permission!Please delete it mannually"<<logfilename<<"locker rental record"<<endl;
						}
						f.put(true); // firstlogin=true
					case '3':
						f.put(true); // banned=true
						break;
					case '1':
						f.put(false); // banned=false
						break;
				}

				cout<<"_________________________Operation completed successfully";
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
	cout<<"1.Confirm the change of ID else.Cancel:";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)+1)); //这里不关心banned位
		f.put(false); // firstlogin=true
		cout<<"\nPlease input your information(If the first character is \'%\',no modification will be allowd)"<<endl;
		cout<<"Username:";
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
					cout<<"\tThe two passwords you typed do not match"<<'\r';
					continue;
				}
				encryptPWD(t.pwd,targetid); //密码加密
			}
		} while(false);
		f.write((char *)&t.pwd,30); //写入新密码
		cout<<"\n_________________________Operation completed successfully";
	}
	f.close();
}


