#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
//Student��Ķ��岿�ִ���ڽӿ��ļ�student.h��
class Student {
	private:
		int number;
		char *name;
		float score;
	public:
		Student(int number1,char *name1,float score1) {
			number=number1;
			name=new char[strlen(name1)+1];
			strcpy(name,name1);
			score=score1;
		}
		~Student() {
			delete []name;
		}
		void modify(float score1) {
			score=score1;
		}
		void print() {
			cout<<"number:"<<number<<"\tname:"<<name<<"\tscore:"<<score<<endl;
		}
		friend ostream &operator << (ostream &os, Student d){
			os << "��ţ�" << d.number << "/t���֣�" << d.name << "/t�ɼ���" << d.score << endl;
			return os;
		}
};

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


	cout << "�ļ�������..." << endl;
	ofstream out("D://TeachAndTest/testFile/STUD.txt", ios::binary);
	out.write((char *) &stu1, sizeof(stu1));
	out.write((char *) &stu2, sizeof(stu2));
	out.close();
	ifstream in("D://TeachAndTest/testFile/STUD.txt", ios::binary);
	
	in.read((char *) &stu2, sizeof(stu2));
	in.read((char *) &stu1, sizeof(stu1));
	in.close();
	stu1.print();
	stu2.print();
	return 0;
}
