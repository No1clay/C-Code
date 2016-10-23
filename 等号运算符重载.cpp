#include<iostream>
#include<Cstring>
using namespace std;
class stringtest {
	char *name;
	public:
		stringtest(char *n){
			name = new char[strlen(n) + 1];
			strcpy(name ,n);
		}
		~stringtest(){
			delete []name;
		}
		stringtest &operator = (const stringtest &s){
			if(this == &s){
				return *this;
			}
			delete []name;
			name = new char[strlen(s.name) + 1];
			strcpy(name , s.name);
			return *this;
		}
		void print(){
			cout << name << endl;
		}
};
int main(){
	stringtest str1("helloWorld"), str2("c++");
	str1 = str2;
	str1.print();
	str2.print();
	return 0;
}

