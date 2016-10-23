#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	private:
	int number;
	char *name;
	float score;
	public:
		Student(int number1,char *name1,float score1);
		~Student();
		void print();
};

Student::Student(int number1,char *name1,float score1)
{
	number=number1;
	name=new char[strlen(name1)+1];
	strcpy(name,name1);
	score=score1;
}

Student::~Student()
{
	delete []name;
}

void Student::print()
{
	cout<<"number:"<<number<<"\nname"<<name<<"\nscore"<<score<<endl;
}

int main()
{
	Student aSA[]={Student(1,"LiMing",98),Student(1,"Bill",87),Student(3,"Mary",93),Student(4,"Daivd",89),Student(5,"WangFang",85)};
	Student *sp;
	sp=aSA;
	for(int i=0;i<5;i++,sp++){
		sp->print();
		aSA[0].print(); 
	}
	return 0;
}
