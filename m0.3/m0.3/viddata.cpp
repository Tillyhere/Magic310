//�ļ����ƣ�viddatd.cpp
//ժ    Ҫ��viddata���ʵ��
//��ǰ�汾��0.3
//��    �ߣ������
//������ڣ�2019.6.30
//ȡ���汾��0.2
//ԭ �� �ߣ������
//������ڣ�2019.6.29

#include "viddata.h"

void viddata::search() //����Ա����#�ɲ�ѯ����Ӱ�� 
{
	cout<<"~��ѯӰ��"<<endl;
	cin.ignore(1024,'\n');
	cout<<"1.��ʼ��ѯ else.�������˵� :";
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::binary);
		string sample;
		do { //��ʼ����ѭ��
			f.seekg(0);
			cout<<"\t������ؼ��ֻ�ȫ�� :";
			cin>>sample;
			cout<<"\nID\tӰƬ��\t����\t�����\tdeleted?"<<endl;
			readData(f);
			do { //��ʼ�����ļ�
				if((t.id.find(sample))!=string::npos||(t.name.find(sample))!=string::npos) { //�ؼ���/ȫ��ƥ��
					showData();
				}
				readData(f);
			} while(!f.eof());
			cout<<"_________________________��������"<<endl;
			f.clear();

			cout<<"\n1.������ѯ else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::add() //����Ա����#������µ�Ӱ�� 
{
	cout<<"~��������"<<endl;
	cout<<"���棺id��ӰƬ�����ܰ����ո����ͬid��ͬ���ֵ�ӰƬ����ʹ�ø������ݹ��ܣ�"<<endl;
	cout<<"1.��ʼ��� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::app|ios::binary);
		state=true;
		do {
			cout<<"\nID\tӰƬ��\t����\t����� (���Կո�ָ�"<<endl;
			cin>>t.id>>t.name>>t.num_in>>t.num_out;
			if(cin.fail()) { //�������������Ⱦ�ļ�
				cout<<"_________________________���棺�����˴�����Ϣ��";
				cin.clear();
				continue; //��������
			} else {
				writeData(f);
				cout<<"_________________________��ӳɹ�"<<endl;

				cout<<"\n1.������� else.�������˵� :";
				cin.ignore(1024,'\n');
				if(cin.get()!='1') {
					break;
				}
			}
		} while(1);
		f.close();
	}
}

void viddata::update() //����Ա����#�ɸ���Ӱ������������� 
{
	cout<<"~��������"<<endl;
	cout<<"1.��ʼ���� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //��ʼ����ѭ��
			f.seekg(0);
			cout<<"\t���������ӰƬȫid :";
			cin>>sample;
			readData(f);
			do { //��ʼ�����ļ�
				if(!state) {	}
				else if(t.id==sample) { //ƥ��ɹ�����ʼ����
					cout<<"\nӰƬid:\t"<<t.id
					    <<"\nӰƬ��:\t"<<t.name
					    <<"\n����:\t"<<t.num_in
					    <<"\n�����:\t"<<t.num_out<<endl;
					cout<<"1.ȷ�ϸ��¸�ӰƬ else.ȡ������ :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						cout<<"\t�������µ����� ����� :";
						cin.ignore(1024,'\n');
						cin>>t.num_in>>t.num_out;
						if(cin.fail()) {
							cout<<"_________________________���棺������Υ����Ϣ��"<<endl;
							cin.clear();
							continue; //��������
						} else {
							f.seekp((int)-(6+t.id.length()+t.name.length()),ios::cur); //���˵�����ͷ�� 2+2+1+1=6
							f.write((char *)&t,4);
							cout<<"_________________________���³ɹ�"<<endl;
						}
					}
					break; //��������
				}
				readData(f);
			} while(!f.eof());
			f.clear();

			cout<<"\n1.�������� else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::vidDelRec() //����Ա����#��ɾ���ָ�Ӱ�� 
{
	cout<<"~����Ӱ��"<<endl;
	cin.ignore(1024,'\n');
	cout<<"1.����ӰƬID��ӰƬ�� else.�������˵� :";
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //��ʼ����ѭ��
			f.seekg(0);
			cout<<"\t������ӰƬid��ӰƬ�� :";
			cin>>sample;
			readData(f);
			do { //��ʼ�����ļ�
				if(t.id==sample||t.name==sample) { //ƥ��ɹ�
					cout<<"\nӰƬid:\t"<<t.id
					    <<"\nӰƬ��:\t"<<t.name
					    <<"\n����:\t"<<t.num_in
					    <<"\n�����:\t"<<t.num_out
					    <<"\ndeleted?"<<(state ? 'N' : 'Y')<<endl;
					cout<<"1.ɾ����ӰƬ 2.�ָ���ӰƬ else.ȡ������ :";
					cin.ignore(1024,'\n');
					switch(cin.get()) { //������ݴ���
						case '1':
							f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //���˵�����ͷ��
							f.put(false);
							break;
						case '2':
							f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //���˵�����ͷ��
							f.put(true);
							break;
						default:
							break;
					}
					cout<<"_________________________�����ɹ�"<<endl;
				}
				readData(f);
			} while(!f.eof());
			f.clear();

			cin.ignore(1024,'\n');
			cout<<"\n1.�������� else.�������˵� :";
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::vidInOut(const int userid,const char *username) //���й���#������黹Ӱ����useridΪ������ID������ԱĬ��0����usernameΪ��������������ԱĬ��Administrator�� 
{
	cout<<"~���/�黹Ӱ��"<<endl;
	cout<<"��ܰ��ʾ����ϵͳ���Ҳ������/�黹��Ӱ��������ϵ����Ա"<<endl;
	cin.ignore(1024,'\n');
	cout<<"1.����ӰƬID��ӰƬ�� else.�������˵� :";
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do {
			f.seekg(0);
			cout<<"\t������ӰƬid��ӰƬ�� :";
			cin>>sample;
			readData(f);
			do { //��ʼ�����ļ�
				if(!state) { }
				else if(t.id==sample||t.name==sample) {
					cout<<"\nӰƬid:\t"<<t.id
					    <<"\nӰƬ��:\t"<<t.name<<endl;
					cout<<"1.�黹��ӰƬ 2.�����ӰƬ else.ȡ������ :";
					cin.ignore(1024,'\n');
					switch(cin.get()) { //������ݴ���
						case '1':
							t.num_in++,t.num_out--;
							sample="Return"; //�û���Ϊ
							break;
						case '2':
							t.num_in--,t.num_out++;
							sample="Borrow";
							break;
						default:
							break;
					}
					if(t.num_out<0||t.num_in<0) {
						cout<<"ϵͳ��ӰƬ������������ϵ����Ա!";
						break;
					} else {
						f.seekp((int)-(6+t.id.length()+t.name.length()),ios::cur);
						f.write((char *)&t,4);

						char logfilename[28]= {0}; //��־�ļ�
						sprintf(logfilename,"./datas/userdatas/%d.csv",userid);
						fstream f_log(logfilename,ios::app);
						f_log<<getCurrentTimeStr()
						     <<','<<username<<','<<userid
						     <<','<<sample
						     <<','<<t.name<<','<<t.id<<endl;
						f_log.close();
						cout<<"_________________________�����ɹ�";
						break;
					}
				}
				readData(f);
			} while(!f.eof());
			f.clear();

			cout<<"\n1.�������/�黹 else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::rebuiltFile() //����Ա����#�������ϳ���ɾ��Ӱ�� 
{
	cout<<"~�����ļ�"<<endl;
	cout<<"���棺��������ӰƬ�����ļ���ԭ���ݽ����ݵ�"<<filename<<".bak�ļ���"<<endl;
	cout<<"1.ȷ������ else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		cin.get();
		string oldfile(filename);
		oldfile.append(".bak"); //filename.bak�����ļ���
		while(rename(filename,oldfile.data())) { //����bak�ļ��ᵼ��������Դ�ļ�ʧ��
			cout<<"\nȨ���쳣���볢��ɾ������"<<filename<<".bak�ļ���Ȼ�󰴻س����ԡ�";
			cin.get();
		}
		fstream f_old((oldfile.data()),ios::in|ios::binary);
		fstream f_new(filename,ios::out|ios::binary);
		if(f_new.fail()) { //����ʧ���˳�
			cout<<"\n���ļ�����ʧ�ܣ������ǰ�ԭ�ļ����ݵ���"<<filename<<".bak�ļ���"<<endl;
			sleep(2);
			exit(200);
		}
		readData(f_old);
		do { //��ʼ�����ļ�
			if(state) { //���ݴ������ļ�
				writeData(f_new);
			}
			readData(f_old);
		} while(!f_old.eof());

		cout<<"_________________________����ɹ�";
		sleep(1);
		f_old.close();
		f_new.close();
	}
}
