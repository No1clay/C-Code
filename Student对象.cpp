#include<iostream>
#include<string.h>
using namespace std;
class Score{
	float computer;
	float english;
	float mathematics;
	public:
		Score(float x1,float y1,float z1);
		Score();
		void print();
		void modify(float x2,float y2,float z2);
};
Score::Score(float x1,float y1,float z1){
	computer=x1;
	english=y1;
	mathematics=z1;
}
Score::Score(){
	computer=english=mathematics=0;
} 
void Score::print(){
	cout<<"The computer score is "<<computer<<endl;
	cout<<"The english score is "<<english<<endl;
	cout<<"The mathematics score is "<<mathematics<<endl;
}
void Score::modify(float x2,float y2,float z2){
	computer=x2;
	english=y2;
	mathematics=z2;
}
class Student{
	int number;
	char *name;
	Score score;
	public:
		Student(int nn,char *str,float x3,float y3,float z3);
		Student(int nn,char *str);
		~Student();
		void print(){
			cout<<"The No."<<number<<" student's name is "<<name<<endl;
			score.print();
		}
		void modify(float x2,float y2,float z2){
			score.modify(x2,y2,z2);
		}
};
Student::Student(int nn,char *str,float x3,float y3,float z3):score(x3,y3,z3){
	number=nn;
	name=new char[strlen(str)+1];
	strcpy(name,str);
}
Student::Student(int nn,char *str){
	number=nn;
	name=new char[strlen(str)+1];
	strcpy(name,str);
}
Student::~Student(){
	delete []name;
}
int main(){
	Student one(1,"xiaoming");
	one.print();
	Student two(1,"xiaoming",122,145,126);
	two.print();
	one.modify(125,125,125);
	one.print();
	return 0;
}
 
