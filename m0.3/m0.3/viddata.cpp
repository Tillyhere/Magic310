//文件名称：viddatd.cpp
//摘    要：viddata类的实现
//当前版本：0.3
//作    者：杨彦军
//完成日期：2019.6.30
//取代版本：0.2
//原 作 者：杨彦军
//完成日期：2019.6.29

#include "viddata.h"

void viddata::search() //管理员工具#可查询所有影碟 
{
	cout<<"~查询影碟"<<endl;
	cin.ignore(1024,'\n');
	cout<<"1.开始查询 else.返回主菜单 :";
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::binary);
		string sample;
		do { //开始搜索循环
			f.seekg(0);
			cout<<"\t请输入关键字或全字 :";
			cin>>sample;
			cout<<"\nID\t影片名\t余量\t租出量\tdeleted?"<<endl;
			readData(f);
			do { //开始遍历文件
				if((t.id.find(sample))!=string::npos||(t.name.find(sample))!=string::npos) { //关键字/全字匹配
					showData();
				}
				readData(f);
			} while(!f.eof());
			cout<<"_________________________搜索结束"<<endl;
			f.clear();

			cout<<"\n1.继续查询 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::add() //管理员工具#可添加新的影碟 
{
	cout<<"~增加数据"<<endl;
	cout<<"警告：id及影片名不能包含空格。添加同id、同名字的影片，请使用更新数据功能！"<<endl;
	cout<<"1.开始添加 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
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
				writeData(f);
				cout<<"_________________________添加成功"<<endl;

				cout<<"\n1.继续添加 else.返回主菜单 :";
				cin.ignore(1024,'\n');
				if(cin.get()!='1') {
					break;
				}
			}
		} while(1);
		f.close();
	}
}

void viddata::update() //管理员工具#可更新影碟余量和租出量 
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
			readData(f);
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
				readData(f);
			} while(!f.eof());
			f.clear();

			cout<<"\n1.更新其他 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::vidDelRec() //管理员工具#可删除恢复影碟 
{
	cout<<"~管理影碟"<<endl;
	cin.ignore(1024,'\n');
	cout<<"1.输入影片ID或影片名 else.返回主菜单 :";
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do { //开始管理循环
			f.seekg(0);
			cout<<"\t请输入影片id或影片名 :";
			cin>>sample;
			readData(f);
			do { //开始遍历文件
				if(t.id==sample||t.name==sample) { //匹配成功
					cout<<"\n影片id:\t"<<t.id
					    <<"\n影片名:\t"<<t.name
					    <<"\n余量:\t"<<t.num_in
					    <<"\n租出量:\t"<<t.num_out
					    <<"\ndeleted?"<<(state ? 'N' : 'Y')<<endl;
					cout<<"1.删除该影片 2.恢复该影片 else.取消操作 :";
					cin.ignore(1024,'\n');
					switch(cin.get()) { //租借数据处理
						case '1':
							f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //回退到数据头部
							f.put(false);
							break;
						case '2':
							f.seekp((int)-(7+t.id.length()+t.name.length()),ios::cur); //回退到数据头部
							f.put(true);
							break;
						default:
							break;
					}
					cout<<"_________________________操作成功"<<endl;
				}
				readData(f);
			} while(!f.eof());
			f.clear();

			cin.ignore(1024,'\n');
			cout<<"\n1.管理其他 else.返回主菜单 :";
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::vidInOut(const int userid,const char *username) //共有功能#可租出归还影碟，userid为操作者ID（管理员默认0），username为操作者名（管理员默认Administrator） 
{
	cout<<"~租出/归还影碟"<<endl;
	cout<<"温馨提示：若系统中找不到租出/归还的影碟，请联系管理员"<<endl;
	cin.ignore(1024,'\n');
	cout<<"1.输入影片ID或影片名 else.返回主菜单 :";
	if(cin.get()=='1') {
		fstream f(filename,ios::in|ios::out|ios::binary);
		string sample;
		do {
			f.seekg(0);
			cout<<"\t请输入影片id或影片名 :";
			cin>>sample;
			readData(f);
			do { //开始遍历文件
				if(!state) { }
				else if(t.id==sample||t.name==sample) {
					cout<<"\n影片id:\t"<<t.id
					    <<"\n影片名:\t"<<t.name<<endl;
					cout<<"1.归还该影片 2.租出该影片 else.取消操作 :";
					cin.ignore(1024,'\n');
					switch(cin.get()) { //租借数据处理
						case '1':
							t.num_in++,t.num_out--;
							sample="Return"; //用户行为
							break;
						case '2':
							t.num_in--,t.num_out++;
							sample="Borrow";
							break;
						default:
							break;
					}
					if(t.num_out<0||t.num_in<0) {
						cout<<"系统内影片数据有误，请联系管理员!";
						break;
					} else {
						f.seekp((int)-(6+t.id.length()+t.name.length()),ios::cur);
						f.write((char *)&t,4);

						char logfilename[28]= {0}; //日志文件
						sprintf(logfilename,"./datas/userdatas/%d.csv",userid);
						fstream f_log(logfilename,ios::app);
						f_log<<getCurrentTimeStr()
						     <<','<<username<<','<<userid
						     <<','<<sample
						     <<','<<t.name<<','<<t.id<<endl;
						f_log.close();
						cout<<"_________________________操作成功";
						break;
					}
				}
				readData(f);
			} while(!f.eof());
			f.clear();

			cout<<"\n1.继续租出/归还 else.返回主菜单 :";
			cin.ignore(1024,'\n');
		} while(cin.get()=='1');
		f.close();
	}
}

void viddata::rebuiltFile() //管理员工具#可物理上彻底删除影碟 
{
	cout<<"~重组文件"<<endl;
	cout<<"警告：即将重组影片数据文件！原数据将备份到"<<filename<<".bak文件中"<<endl;
	cout<<"1.确认重组 else.返回主菜单 :";
	cin.ignore(1024,'\n');
	if(cin.get()=='1') {
		cin.get();
		string oldfile(filename);
		oldfile.append(".bak"); //filename.bak备份文件名
		while(rename(filename,oldfile.data())) { //已有bak文件会导致重命名源文件失败
			cout<<"\n权限异常，请尝试删除已有"<<filename<<".bak文件，然后按回车重试。";
			cin.get();
		}
		fstream f_old((oldfile.data()),ios::in|ios::binary);
		fstream f_new(filename,ios::out|ios::binary);
		if(f_new.fail()) { //创建失败退出
			cout<<"\n新文件创建失败，但我们把原文件备份到了"<<filename<<".bak文件中"<<endl;
			sleep(2);
			exit(200);
		}
		readData(f_old);
		do { //开始遍历文件
			if(state) { //数据存入新文件
				writeData(f_new);
			}
			readData(f_old);
		} while(!f_old.eof());

		cout<<"_________________________重组成功";
		sleep(1);
		f_old.close();
		f_new.close();
	}
}
