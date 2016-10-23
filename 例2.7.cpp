#include<iostream>
#include<string.h>
using namespace std;
//Student类的定义部分存放在接口文件student.h中
class Student {
	private:
		int number;
		char *name;
		float score;
	public:
		Student(int number1,char *name1,float score1);
		~Student();
		void modify(float score1) {
			score=score1;
		}
		void print();
};
Student::Student(int number1,char *name1,float score1) {
	number=number1;
	name=new char[strlen(name1)+1];
	strcpy(name,name1);
	score=score1;
}
Student::~Student() {
	delete []name;
}
void Student::print() {
	cout<<"number:"<<number<<"name:"<<name<<"score:"<<score<<endl;
}
int main() {
	int numberi;
	char namei[15];
	float scorei;

	cout<<"Enter number:"<<endl;
	cin>>numberi;
	cout<<"Enter name:"<<endl;
	cin>>namei;
	cout<<"Enter score"<<endl;
	cin>>scorei;
	Student stu1(numberi,namei,scorei);

	cout<<"Enter number:"<<endl;
	cin>>numberi;
	cout<<"Enter name:"<<endl;
	cin>>namei;
	Student stu2(numberi,namei,scorei);
	stu2.modify(87);
	
	stu1.print();
	stu2.print();
	return 0; 
}
