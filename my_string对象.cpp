#include<iostream>
#include<string.h>
using namespace std;
class my_string{
	char *contents;
	int length;
	public:
		my_string(char *str){
			contents=new char[strlen(str)+1];
			strcpy(contents,str);
			length=strlen(str);
		}
		void print(){
			cout<<"The string is "<<contents<<endl;
		}
		int getStrLength(){
			length=strlen(contents); 
			return length;
		}
		void addStr(char *str){
			char *dest;
			dest=new char[length+strlen(str)+1];
			strcpy(dest,contents);
			strcat(dest,str); 
			contents=dest;
			delete []dest;
		}
		~my_string(){
			delete []contents;
		}
};
int main(){
	char str[100];
	cout <<"Please intput a string :"<<endl;
	cin.getline(str,99);
	my_string one(str);
	one.print();
	cout<<"The length of the string is "<<one.getStrLength()<<endl;
	cout <<"Please intput a string :"<<endl;
	cin.getline(str,99);
	one.addStr(str);
	one.print(); 
	cout<<"The length of the string is "<<one.getStrLength()<<endl;
	return 0;
}

