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
	cout<<"~��ѯ�û�"<<endl;
	fstream f(filename,ios::in|ios::binary);
	do {
		cout<<"1.ID��ѯ 2.�û�����ѯ else.�������˵� :";
		int targetid=0;
		cin>>targetid;
		if(targetid==1) {
			cout<<"\t�������û�ID :";
			cin>>targetid;
			f.seekg((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
			readData(f);
			cout<<"\nID\t�û���\t\t������״̬"<<endl;
			showData();
		} else if(targetid==2) {
			string sample;
			string matchsample;
			f.seekg(0);
			cout<<"\t�������û����ؼ��� :";
			cin>>matchsample;
			cout<<"\nID\t�û���\t\t������״̬"<<endl;
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
		cout<<"_________________________��������"<<endl;
		cout<<"\n1.������ѯ else.�������˵� :";
		cin.ignore(1024,'\n');
	} while(cin.get()=='1');
	f.close();
}

void userdata::createProfile()
{
	cout<<"~������Ա��"<<endl;
	cout<<"��ʾ��1.��һ�δ���ʱ��id����ʼ��������0���û�id��0��ʼ\n"
	    <<"      2.������id�λḲ��ԭid����Ϣ�����������뼰����¼���������ڸ���ԭ�û���Ϣ��"<<endl;
	cout<<"1.��ʼ���� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		banned=false;
		firstlogin=true;
		int startid=0,endid=0;
		do {
			cout<<"\t������id�ε���ʼ�� ��ֹ�� :" ;
			cin>>startid>>endid;
			if(cin.fail()) { //�������������Ⱦ�ļ�
				cout<<"_________________________���棺�����˴�����Ϣ��"<<endl;
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
					f_log<<"ʱ��"<<','<<"�û���"<<','<<"�û�ID"<<','<<"���/�黹"<<','<<"ӰƬ��"<<','<<"ӰƬID"<<endl;
					f_log.close();
				}

				cout<<"_________________________����id��"<<startid<<"��"<<endid<<"�ɹ�";
				sleep(1);
				break;
			}
		} while(1);
		f.close();
	}
}

void userdata::manageID()
{
	cout<<"~�û�ID����"<<endl;
	cout<<"��ʾ��\t1.�����û�ID���ܾ����û���¼ϵͳ��������ID�����Ϣ��"<<endl
	    <<"\t2.����û�ID���ָ��������û���Ȩ�ޣ����޷��ָ������յ����ݡ�"<<endl
	    <<"\t3.�����û�ID������ɾ����ID���û���Ϣ������¼,ID����Ϊδע��״̬��"<<endl;
	cout<<"1.����ID else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
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
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				readData(f);
				f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)));
				cout<<"\n�û�ID:\t"<<t.id
				    <<"\n�û���:\t"<<t.name<<endl;
				cout<<"1.����ID 2.���ڲ�����ID 3.�����ڸ�ID else.ȡ������ :";
				cin.ignore(1024,'\n');
				char logfilename[28]= {0};
				switch(cin.get()) {
					case '2':
						sprintf(logfilename,"./datas/userdatas/%d.csv",targetid);
						if(remove(logfilename)) { //��ɾ��ʧ��
							cout<<"\nȨ���쳣�����ֶ�ɾ��"<<logfilename<<"����¼�ļ�"<<endl;
						}
						f.put(true); // firstlogin=true
					case '3':
						f.put(true); // banned=true
						break;
					case '1':
						f.put(false); // banned=false
						break;
				}

				cout<<"_________________________�����ɹ�";
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
	cout<<"1.ȷ���޸Ĵ�ID else.ȡ������ :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		f.seekp((int)(targetid*(2+sizeof(userdata::temp_data)+1)+1)); //���ﲻ����bannedλ
		f.put(false); // firstlogin=true
		cout<<"\n��������Ϣ(���ַ�����\'%\'��ʾ��������)"<<endl;
		cout<<"�û���:";
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
					cout<<"\t�������벻һ��!"<<'\r';
					continue;
				}
				encryptPWD(t.pwd,targetid); //�������
			}
		} while(false);
		f.write((char *)&t.pwd,30); //д��������
		cout<<"\n_________________________�����ɹ�";
	}
	f.close();
}


