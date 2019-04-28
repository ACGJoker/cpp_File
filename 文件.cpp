#include<iostream>
#include<fstream>
//#include<iomanip>
using namespace std;

class Student
{
private:
	char *major;
	//指针数据成员不能无格式
	//major[10]可以无格式
	int id;
public:
	Student(int i,char* m){id=i;
		major=new char[strlen(m)+1];
		strcpy(major,m);
	}
	void print(){cout<<id<<" "<<major<<endl;}
	~Student(){if(major)delete []major;}

};

class Date
{
private:

	int year,month,day;
public:
	Date(int y,int m,int d):year(y),month(m),day(d){}
	void print(){cout<<year<<" "<<month<<" "<<day<<endl;}
	friend ostream& operator<<(ostream&os,Date d);
	friend istream& operator>>(istream&is,Date& d);
};

ostream& operator<<(ostream&os,Date d)
{
	os<<d.year<<" "<<d.month<<" "<<d.day;
	return os;
}
istream& operator>>(istream&is,Date& d)//输入流重载一定引用
{
	is>>d.year>>d.month>>d.day;
	return is;
}

int main()
{
	//ofstream outfile;
	//outfile.open("d:\\story.txt",ios::app|ios::out);
	//if(!outfile){
	//	cout<<"can't find file"<<endl;
	//	return 1;
	//}//检测是否创建成功
	//outfile<<"C++"<<endl;
	//outfile<<"Python!"<<endl;
	//outfile.close();

	/*
	ifstream infile("d:\\story.txt",ios::in);
	if(!infile){
		cout<<"can't find file"<<endl;	
	}
	char s[80];
	while(!infile.eof()){
		infile.getline(s,'\n');
		cout<<s<<endl;
	}
	infile.close();
	*/
	/*
	ofstream outfile;
	Date dt(2000,2,1);
	Date dt2(1000,12,12);
	outfile.open("d:\\story1.txt",ios::app|ios::out);
	if(!outfile){
		cout<<"can't find file"<<endl;
		return 1;
	}//检测是否创建成功
	outfile<<dt2<<endl;	
	outfile<<dt<<endl;
	outfile.close();
	*/
	/*
	ifstream infile("d:\\story1.txt",ios::in);
	if(!infile){
		cout<<"can't find file"<<endl;	
	}
	Date d(0,0,0);
	infile>>d;
	d.print();

	infile.close();
	*/
	/*
	ifstream infile("d:\\story1.txt",ios::in);
	if(!infile){
		cout<<"can't find file"<<endl;	
	}
	Date d(0,0,0);

	//防止结尾重复显示
	infile>>d;
	while(!infile.eof()){
		d.print();
		infile>>d;
	}
	infile.close();*/

	/*------------------------------------------------------------------*/
	//无格式写入，读取文件

	//
	//ofstream outfile;
	//Date dt(2000,2,1);
	//Date dt2(100,100,100);
	//Date dt3(255,255,255);

	//outfile.open("d:\\story2.txt",ios::out|ios::binary);
	//if(!outfile){
	//	cout<<"can't find file"<<endl;
	//	return 1;
	//}
	//outfile.write((char*)&dt,sizeof(Date));
	//outfile.write((char*)&dt2,sizeof(Date));
	//outfile.write((char*)&dt3,sizeof(Date));
	//outfile.close();//注意close，数据一致性
	//
	////并发访问
	//ifstream infile("d:\\story2.txt",ios::in);
	//if(!infile){
	//	cout<<"can't find file"<<endl;	
	//}
	//Date d(0,0,0);

	//infile.read((char*)&d,sizeof(Date));
	//while(!infile.eof()){
	//	d.print();
	//	infile.read((char*)&d,sizeof(Date));
	//}
	//infile.close();

	/*------------------------------------------------------------------*/

	/*ofstream outfile;
	Student s1(1,"SE");
	outfile.open("d:\\story2.txt",ios::out|ios::binary);
	if(!outfile){cout<<"can't find file"<<endl;return 1;}
	outfile.write((char*)&s1,sizeof(Student));
	outfile.close();*/


	ifstream infile("d:\\story2.txt",ios::in);
	if(!infile){cout<<"can't find file"<<endl;	}
	Student s(0,"No Major");
	infile.read((char*)&s,sizeof(Student));
	while(!infile.eof()){
		s.print();
		infile.read((char*)&s,sizeof(Date));
	}
	infile.close();

}