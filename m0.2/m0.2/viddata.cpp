//�ļ����ƣ�viddatd.cpp
//ժ    Ҫ��viddata���ʵ��
//��ǰ�汾��0.2
//��    �ߣ������
//������ڣ�2019.6.29
//ȡ���汾��0.1
//ԭ �� �ߣ������
//������ڣ�2019.6.28

#include "def_class.h"

void viddata::search()
{
	cout<<"~��ѯ����"<<endl;
	cout<<"1.��ʼ��ѯ else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::binary);
		string sample;
		do { //��ʼ����ѭ��
			f.seekg(0);
			cout<<"\t������ؼ��ֻ�ȫ�� :";
			cin>>sample;
			cout<<"\nID\tӰƬ��\t����\t�����"<<endl;
			readdata(f);
			do { //��ʼ�����ļ�
				if(!state) {	}
				else if((t.id.find(sample))!=string::npos||(t.name.find(sample))!=string::npos) { //�ؼ���/ȫ��ƥ��
					showdata();
				}
				readdata(f);
			} while(!f.eof());
			cout<<"_________________________��������"<<endl; 
			f.clear();
			cout<<"\n1.������ѯ else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::add()
{
	cout<<"~��������"<<endl;
	cout<<"���棺id��ӰƬ�����ܰ����ո����ͬid��ͬ���ֵ�ӰƬ����ʹ�ø������ݹ��ܣ�"<<endl;
	cout<<"1.��ʼ��� 2.�������� else.�������˵� :";
	cin.ignore(1024,'\n');
	char section;
	cin>>section;
	if(section=='1') {
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
				writedata(f);
				cout<<"_________________________��ӳɹ�"<<endl; 
			}
			cout<<"\n1.������� else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	} else if(section=='2')	{
		this->update();
	}
}

void viddata::update()
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
			readdata(f);
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
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.�������� else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::del()
{
	cout<<"~ɾ������"<<endl;
	cout<<"1.��ʼɾ�� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //��ʼɾ��ѭ��
			f.seekg(0);
			cout<<"\t������ɾ��ӰƬ����id :"; //��ѡ�����е㸴����QAQ
			cin>>sample;
			readdata(f);
			do { //��ʼ�����ļ�
				if(!state) {	}
				else if(t.id==sample) { //ƥ��ɹ�����ʼɾ��
					cout<<"\nӰƬid:\t"<<t.id
					    <<"\nӰƬ��:\t"<<t.name
						<<"\n����:\t"<<t.num_in
						<<"\n�����:\t"<<t.num_out<<endl;
					cout<<"1.ȷ��ɾ����ӰƬ else.ȡ��ɾ�� :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //���˵�����ͷ��
						f.put(false);
						cout<<"_________________________ɾ���ɹ�"<<endl; 
					}
					break; //��������
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.ɾ������ else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::rec()
{
	cout<<"~�ָ�����"<<endl;
	cout<<"1.��ʼ�ָ� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //��ʼ�ָ�ѭ��
			f.seekg(0);
			cout<<"\t������ָ�ӰƬ����id :";
			cin>>sample;
			readdata(f);
			do { //��ʼ�����ļ�
				if(state) {	}
				else if(t.id==sample) { //ƥ��ɹ�����ʼ�ָ� 
					cout<<"\nӰƬid:\t"<<t.id
					    <<"\nӰƬ��:\t"<<t.name
						<<"\n����:\t"<<t.num_in
						<<"\n�����:\t"<<t.num_out<<endl;
					cout<<"1.ȷ�ϻָ���ӰƬ else.ȡ���ָ� :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //���˵�����ͷ��
						f.put(true);
						cout<<"_________________________�ָ��ɹ�"<<endl; 
					}
					break; //��������
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.�ָ����� else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::in()
{
	cout<<"~�黹Ӱ��"<<endl;
	cout<<"�ͻ���ܰ��ʾ�����Ҳ����黹��Ӱ������ϵ����Ա"<<endl; //����ӰƬ��ɾ���˰ɣ��ҹ���Ա
	cout<<"1.��ʼ�黹 else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //��ʼ�黹ѭ��
			f.seekg(0);
			cout<<"\t������ӰƬ����id��ӰƬ�� :";
			cin>>sample;
			readdata(f);
			do { //��ʼ�����ļ�
				if(!state) {	}
				else if(t.id==sample||t.name==sample) {
					cout<<"\nӰƬid:\t"<<t.id
					    <<"\nӰƬ��:\t"<<t.name<<endl;
					cout<<"1.ȷ�Ϲ黹��ӰƬ else.ȡ������ :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						t.num_in++,t.num_out--;
						if(t.num_out<0) {
							cout<<"�黹�����ڼ�¼��!"; //
							break;
						}
						f.seekp((int)-(6+t.id.length()+t.name.length()),ios::cur);
						f.write((char *)&t,4);
						cout<<"_________________________�黹�ɹ�";
					}
					break;
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.�����黹 else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::out()
{
	cout<<"~���Ӱ��"<<endl;
	cout<<"1.��ʼ��� else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //��ʼ���ѭ��
			f.seekg(0);
			cout<<"\t������ӰƬ����id��ӰƬ�� :";
			cin>>sample;
			readdata(f);
			do { //��ʼ�����ļ�
				if(!state) {	}
				else if(t.id==sample||t.name==sample) {
					cout<<"1.ȷ�������ӰƬ >-id��"<<t.id<<" ӰƬ����"<<t.name<<"-<"
					    <<"\nelse.������������ı�������ʽ����ϵ����Ա����"; //����ӰƬ��ɾ���˰ɣ��ҹ���Ա
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						t.num_in--,t.num_out++;
						if(t.num_out<0) {
							cout<<"��������!����ʵ��update"; //
							break;
						}
						f.seekp(-(6+t.id.length()+t.name.length()),ios::cur);
						f.write((char *)&t,4);
						cout<<"~����ɹ�";
					}
					break;
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.������� else.�������˵� :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::rebuiltfile()
{
	cout<<"~�����ļ�"<<endl;
	cout<<"���棺��������ӰƬ�����ļ���ԭ���ݽ����ݵ�"<<filename<<".bak�ļ���"<<endl;
	cout<<"1.ȷ������ else.�������˵� :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		string oldfile(filename); //
		oldfile.append(".bak"); //filename.bak�����ļ���
		while(rename(filename,oldfile.data())) { //����bak�ļ��ᵼ��������Դ�ļ�ʧ��
			cout<<"\nȨ���쳣���볢��ɾ������"<<filename<<".bak�ļ���Ȼ�󰴻س����ԡ�";
			cin.get();
		}
		fstream f_old((oldfile.data()),ios::in|ios::binary);
		fstream f_new(filename,ios::out|ios::binary);
		if(f_new.fail()){ //����ʧ���˳� 
			cout<<"\n�ļ�����ʧ�ܣ������ǰ�ԭ���ݱ��ݵ���"<<filename<<".bak�ļ���"<<endl;
			cin.get();
			exit(200);
		} 
		readdata(f_old);
		do { //��ʼ�����ļ�
			if(state){ //���ݴ������ļ�
				writedata(f_new);
			} 
			readdata(f_old);
		} while(!f_old.eof());
		cout<<"_________________________����ɹ�";
		cin.get();
		f_old.close();
		f_new.close();
	}
}
