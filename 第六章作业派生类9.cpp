#include<iostream>
#include<Cstring> 
using namespace std;
class Person{
	public:
		Person(const char *s){
			name = new char[strlen(s) + 1];
			strcpy(name, s);
		}
		~Person(){
			delete []name;
		}
	protected:
		char *name;
};
class Student: public Person{
	protected:
		char *number;
	public:
		Student(const char *s ,char * n):Person(s){
			number = new char [strlen(n) + 1];
			strcpy(number , n);
		}
		void show(){
			cout << "The Student's number is " << number << endl;
			cout << "The Student's name is " << name << endl;
		}
		~Student(){
			delete []number;
		}
};
int main(){
	Student stu("Liziming" , "00000000");
	stu.show();
	return 0;
}

