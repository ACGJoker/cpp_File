#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Student{
private:
    char name[20]; int  score;
public:
    Student(char *na="",int s=0);
    void print();
    void setInfo(char *na,int s);
    ~Student();
    friend ostream& operator<<(ostream& os,Student s);
};
ostream& operator<<(ostream& os,Student s){
    os<<s.name<<' '<< s.score<<endl;
    return os;
}

Student::Student(char *na,int s){
    strcpy(name,na);
    score = s;
}

void Student::setInfo(char* na,int s){
    strcpy(name,na);
    score = s;
}

Student::~Student(){}

void Student::print(){
    cout <<name<<':'<<score<<endl;
}

bool savetofile(char* filename,Student*s,int n){
     ofstream outfile;
     outfile.open(filename,ios::binary);
     if(!outfile)
     {
         cout<<"cann't open the file"<<endl;
         return false;
     }
     for(int i=0;i<n;i++)
         outfile.write((char*)&s[i],sizeof(Student));
    outfile.close();
    return true;
}

int main()
{
    Student st[3];
    char name[20];int score;
    cout <<"please input name,score of the students:"<<endl;
    for(int i=0;i<3;i++)
    {
        cin>>name>>score;
        st[i].setInfo(name,score);
    }
     /*将 st 有格式 保存到磁盘文件 d://info.txt
     ofstream outfile("d:\\info.txt");
     for(int i=0;i<3;i++)
        outfile<<st[i]<<endl;
     outfile.close();
     */
     //将 st 无格式 保存到磁盘文件 d://info.bak
     savetofile("d:\\info1.bak",st,3);


     ifstream  infile("d:\\info1.bak");
     if(!infile)
     {
         cout <<"can't open"<<endl;
         return 1;
     }
     cout<<infile.tellg()<<endl;
	 
	 //随机读
	 Student temp;
	 infile.seekg(sizeof(Student),ios::beg);
	 cout<<infile.tellg();
	 infile.read((char*)&temp,sizeof(Student));
	 temp.print();
     infile.seekg(0,ios::end);
     cout<<infile.tellg()<<endl;
	 infile.close();


	 //ofstream outfile("d:\\info1.bak",ios::binary|ios::app);//ios::app优先级高，一定追加
	 fstream outfile("d:\\info1.bak",ios::in|ios::out);//文件不存在时不创建
	 if(!outfile) return 1;
	 outfile.seekg(0,ios::end);
	 cout<<outfile.tellp()<<endl;
	 outfile.seekp(sizeof(Student),ios::beg);
	 cout<<outfile.tellp()<<endl;
	 temp.setInfo("C++",100);
	 outfile.write((char*)&temp,sizeof(Student));
	 outfile.close();


	 return 0;
}


