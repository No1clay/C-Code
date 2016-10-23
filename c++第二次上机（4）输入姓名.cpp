#include<iostream>
#include<string.h> 
using namespace std;
int main(){
	char *name;
	cout<<"What your name ?"<<endl;
	name=new char [50]; 
	cin.getline(name,49);
	cout <<name;
	delete []name;
	name=NULL;
	return 0;
} 
