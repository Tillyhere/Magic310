//�ļ����ƣ�viddatd.cpp
//ժ    Ҫ��viddata���ʵ��
//��ǰ�汾��0.1
//��    �ߣ������
//������ڣ�2019.6.30
//ȡ���汾��0.0
//ԭ �� �ߣ������
//������ڣ�2019.6.29

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
			do { //��ʼ�����ļ�
				sample=t.name;
				if((sample.find(matchsample))!=string::npos) { //�ؼ���ƥ��
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
	cout<<"Tips��1.When it is first created��Please input 0 into the starting number of ID segment\n"
	
	    <<"      2.Creat new ID segment will cover the old information��name,passwords and rental record)."<<endl;
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
			if(cin.fail()) { //�������������Ⱦ�ļ�
				cout<<"_________________________Warning:Wrong Information was enterd"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //��������
			} else {
				f.seekp((int)(startid*(2+sizeof(userdata::temp_data)+1)));
				char logfilename[28]= {0};
				for(t.id=startid; t.id<=endid; t.id++) {
					writeData(f);
					sprintf(logfilename,"./datas/userdatas/%d.csv",t.id);
					fstream f_log(logfilename,ios::out); //��������¼�ļ�
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
	cout<<"T��\t1.Block the user'ID:Access permission will be cancelled,while information of the ID will be remained."<<endl
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
			if(cin.fail()) { //�������������Ⱦ�ļ�
				cout<<"_________________________Warning:wrong information was entered"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //��������
			} else {
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				readData(f);
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				cout<<"\n�û�ID:\t"<<t.id
				    <<"\n�û���:\t"<<t.name<<endl;
				cout<<"1.Unblock the ID 2.Block and recycle the ID 3.Block the ID only else.Cancel:";
				cin.ignore(1024,'\n');
				char logfilename[28]= {0};
				switch(cin.get()) {
					case '2':
						sprintf(logfilename,"./datas/userdatas/%d.csv",targetid);
						if(remove(logfilename)) { //��ɾ��ʧ��
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

void userdata::manageProfile(int targetid)  //�ͻ��˹���Ա�˹��к���
{
	/*cout<<"~�û���Ϣ����"<<endl; //�ⲿ�ֺ���д������Ա��������
	cout<<"��ʾ��\t���ڰ����û��һ����롣"<<endl
	cout<<"1.����ID else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		int targetid=0;
		do {
			cout<<"\t������Ŀ���û�ID :" ;
			cin>>targetid;
			if(cin.fail()) { //�������������Ⱦ�ļ�
				cout<<"_________________________���棺�����˴�����Ϣ��"<<endl;
				cin.clear();
				cin.ignore(1024,'\n');
				continue; //��������
			} else {
				usr.manageprofile(targetid);
			��
		} while(1);
	}*/
	fstream f(this->filename,ios::in|ios::out|ios::binary);
	f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
	readData(f);
	cout<<"\n�û�ID:\t"<<t.id
	    <<"\n�û���:\t"<<t.name<<endl;
	cout<<"1.Confirm the change of ID else.Cancel:";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)+1)); //���ﲻ����bannedλ
		f.put(false); // firstlogin=true
		cout<<"\nPlease input your information(If the first character is \'%\',no modification will be allowd)"<<endl;
		cout<<"Username:";
		cin.ignore(1024,'\n');
		cin.get(t.name,30);
		if(t.name[0]=='%') {
			f.seekp(30,ios::cur); //ָ�������û���
		} else {
			f.write((char *)&t.name,30); //д�����û���
		}
		do {
			cout<<"�û�����:";
			inputPWD(t.pwd,30);
			if(t.pwd[0]=='%') {
				break;
			} else {
				cout<<"\tȷ������:";
				char pwdcheck[30]= {0};
				inputPWD(pwdcheck,30);
				if(strcmp(pwdcheck,t.pwd)) {
					cout<<"\tThe two passwords you typed do not match"<<'\r';
					continue;
				}
				encryptPWD(t.pwd,targetid); //�������
			}
		} while(false);
		f.write((char *)&t.pwd,30); //д��������
		cout<<"\n_________________________Operation completed successfully";
	}
	f.close();
}


