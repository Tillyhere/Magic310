//文件名称：viddatd.cpp
//摘    要：viddata类的实现
//当前版本：0.2
//作    者：杨彦军
//完成日期：2019.6.29
//取代版本：0.1
//原 作 者：杨彦军
//完成日期：2019.6.28

#include "def_class.h"

void viddata::search()
{
	cout<<"~查询数据"<<endl;
	cout<<"1.开始查询 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::binary);
		string sample;
		do { //开始搜索循环
			f.seekg(0);
			cout<<"\t请输入关键字或全字 :";
			cin>>sample;
			cout<<"\nID\t影片名\t余量\t租出量"<<endl;
			readdata(f);
			do { //开始遍历文件
				if(!state) {	}
				else if((t.id.find(sample))!=string::npos||(t.name.find(sample))!=string::npos) { //关键字/全字匹配
					showdata();
				}
				readdata(f);
			} while(!f.eof());
			cout<<"_________________________搜索结束"<<endl; 
			f.clear();
			cout<<"\n1.继续查询 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::add()
{
	cout<<"~增加数据"<<endl;
	cout<<"警告：id及影片名不能包含空格。添加同id、同名字的影片，请使用更新数据功能！"<<endl;
	cout<<"1.开始添加 2.更新数据 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	char section;
	cin>>section;
	if(section=='1') {
		fstream f(filename,ios::app|ios::binary);
		state=true;
		do {
			cout<<"\nID\t影片名\t余量\t租出量 (请以空格分隔"<<endl;
			cin>>t.id>>t.name>>t.num_in>>t.num_out;
			if(cin.fail()) { //避免错误输入污染文件
				cout<<"_________________________警告：输入了错误信息！";
				cin.clear();
				continue; //重新输入
			} else {
				writedata(f);
				cout<<"_________________________添加成功"<<endl; 
			}
			cout<<"\n1.继续添加 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	} else if(section=='2')	{
		this->update();
	}
}

void viddata::update()
{
	cout<<"~更新数据"<<endl;
	cout<<"1.开始更新 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //开始更新循环
			f.seekg(0);
			cout<<"\t请输入更新影片全id :";
			cin>>sample;
			readdata(f);
			do { //开始遍历文件
				if(!state) {	}
				else if(t.id==sample) { //匹配成功，开始更新
					cout<<"\n影片id:\t"<<t.id
					    <<"\n影片名:\t"<<t.name
						<<"\n余量:\t"<<t.num_in
						<<"\n租出量:\t"<<t.num_out<<endl;
					cout<<"1.确认更新该影片 else.取消更新 :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						cout<<"\t请输入新的余量 租出量 :";
						cin.ignore(1024,'\n');
						cin>>t.num_in>>t.num_out;
						if(cin.fail()) {
							cout<<"_________________________警告：输入了违法信息！"<<endl;
							cin.clear();
							continue; //重新输入
						} else {
							f.seekp((int)-(6+t.id.length()+t.name.length()),ios::cur); //回退到数据头部 2+2+1+1=6
							f.write((char *)&t,4);
							cout<<"_________________________更新成功"<<endl; 
						}
					}
					break; //结束遍历
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.更新其他 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::del()
{
	cout<<"~删除数据"<<endl;
	cout<<"1.开始删除 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //开始删除循环
			f.seekg(0);
			cout<<"\t请输入删除影片完整id :"; //做选择功能有点复杂了QAQ
			cin>>sample;
			readdata(f);
			do { //开始遍历文件
				if(!state) {	}
				else if(t.id==sample) { //匹配成功，开始删除
					cout<<"\n影片id:\t"<<t.id
					    <<"\n影片名:\t"<<t.name
						<<"\n余量:\t"<<t.num_in
						<<"\n租出量:\t"<<t.num_out<<endl;
					cout<<"1.确认删除该影片 else.取消删除 :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //回退到数据头部
						f.put(false);
						cout<<"_________________________删除成功"<<endl; 
					}
					break; //结束遍历
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.删除其他 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::rec()
{
	cout<<"~恢复数据"<<endl;
	cout<<"1.开始恢复 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //开始恢复循环
			f.seekg(0);
			cout<<"\t请输入恢复影片完整id :";
			cin>>sample;
			readdata(f);
			do { //开始遍历文件
				if(state) {	}
				else if(t.id==sample) { //匹配成功，开始恢复 
					cout<<"\n影片id:\t"<<t.id
					    <<"\n影片名:\t"<<t.name
						<<"\n余量:\t"<<t.num_in
						<<"\n租出量:\t"<<t.num_out<<endl;
					cout<<"1.确认恢复该影片 else.取消恢复 :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //回退到数据头部
						f.put(true);
						cout<<"_________________________恢复成功"<<endl; 
					}
					break; //结束遍历
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.恢复其他 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::in()
{
	cout<<"~归还影碟"<<endl;
	cout<<"客户温馨提示：若找不到归还的影碟请联系管理员"<<endl; //可能影片被删除了吧，找管理员
	cout<<"1.开始归还 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //开始归还循环
			f.seekg(0);
			cout<<"\t请输入影片完整id或影片名 :";
			cin>>sample;
			readdata(f);
			do { //开始遍历文件
				if(!state) {	}
				else if(t.id==sample||t.name==sample) {
					cout<<"\n影片id:\t"<<t.id
					    <<"\n影片名:\t"<<t.name<<endl;
					cout<<"1.确认归还该影片 else.取消操作 :";
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						t.num_in++,t.num_out--;
						if(t.num_out<0) {
							cout<<"归还数大于记录数!"; //
							break;
						}
						f.seekp((int)-(6+t.id.length()+t.name.length()),ios::cur);
						f.write((char *)&t,4);
						cout<<"_________________________归还成功";
					}
					break;
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.继续归还 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::out()
{
	cout<<"~租出影碟"<<endl;
	cout<<"1.开始租碟 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //开始租出循环
			f.seekg(0);
			cout<<"\t请输入影片完整id或影片名 :";
			cin>>sample;
			readdata(f);
			do { //开始遍历文件
				if(!state) {	}
				else if(t.id==sample||t.name==sample) {
					cout<<"1.确认租出该影片 >-id："<<t.id<<" 影片名："<<t.name<<"-<"
					    <<"\nelse.重新搜索（请改变搜索方式或联系管理员）："; //可能影片被删除了吧，找管理员
					cin.ignore(1024,'\n');
					if(cin.get()=='1') {
						t.num_in--,t.num_out++;
						if(t.num_out<0) {
							cout<<"余量不足!若属实请update"; //
							break;
						}
						f.seekp(-(6+t.id.length()+t.name.length()),ios::cur);
						f.write((char *)&t,4);
						cout<<"~租出成功";
					}
					break;
				}
				readdata(f);
			} while(!f.eof());
			f.clear();
			cout<<"\n1.继续租碟 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::rebuiltfile()
{
	cout<<"~重组文件"<<endl;
	cout<<"警告：即将重组影片数据文件！原数据将备份到"<<filename<<".bak文件中"<<endl;
	cout<<"1.确认重组 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		string oldfile(filename); //
		oldfile.append(".bak"); //filename.bak备份文件名
		while(rename(filename,oldfile.data())) { //已有bak文件会导致重命名源文件失败
			cout<<"\n权限异常，请尝试删除已有"<<filename<<".bak文件，然后按回车重试。";
			cin.get();
		}
		fstream f_old((oldfile.data()),ios::in|ios::binary);
		fstream f_new(filename,ios::out|ios::binary);
		if(f_new.fail()){ //创建失败退出 
			cout<<"\n文件创建失败，但我们把原数据备份到量"<<filename<<".bak文件中"<<endl;
			cin.get();
			exit(200);
		} 
		readdata(f_old);
		do { //开始遍历文件
			if(state){ //数据存入新文件
				writedata(f_new);
			} 
			readdata(f_old);
		} while(!f_old.eof());
		cout<<"_________________________重组成功";
		cin.get();
		f_old.close();
		f_new.close();
	}
}
