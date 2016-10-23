#include<iostream>
#include<string.h>
using namespace std;
class student{
	char name[20];
	float math;
	float chinese;
	float english;
	static int count;
	static int number; 
	public :
		student(char *name1,float math1,float chinese1,float english1);//构造函数没有返回类型，不需要声明 
		void print(){
			cout<<name<<"'s goods:"<<endl;
			cout<<"math:"<<math<<endl;
			cout<<"chinese:"<<chinese<<endl;
			cout<<"english:"<<english<<endl;
		}
		void modifymath(float math1);
		~student();
};
student::student(char *name1,float math1,float chinese1,float english1){
	strcpy(name,name1);
	math=math1;
	chinese=chinese1;
	english=english1;
	student::number++; //number++;相等 
}
student::~student(){//析构函数 
	cout<<"yes";
}
void student::modifymath(float math1){
	math=math1;
} 
int student::number=0;
int student::count=0;
int main(){
	char name1[20]="liming";
	student stu[3]={student(name1,88.1,88.2,88.3)
	,student(name1,99,100,36.2),student(name1,63.1,55.6,88)}; 
	student *p;//指向对象的指针。
	p=&stu[1];
	cout<<"When you look this,this will be the second student's goods!" <<endl;
	p->print();
	student one(name1,0,0,0);
	one=stu[0];
	cout<<"When you find this on you screen, this will be the first student's goods!"<<endl;
	one.print();
	for(int i=0;i<3;i++){
		stu[i].print();
	}
	//cout<<stu[0].number;//可以将一部分数据设为公有； 
	return 0;
}
