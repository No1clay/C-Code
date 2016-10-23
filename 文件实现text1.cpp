#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ofstream out;
	ifstream in;
	string str;
	out.open("D://TeachAndTest/testFile/test1.txt");
	if(!out){
		cout << "Can't open the file!" << endl;
	}
	out << "Learning C++ programming is fun!" << endl;
	out.close();
	in.open("D://TeachAndTest/testFile/test1.txt");
	if(in == NULL){
		cout << "Can't read the file!" << endl;
	}
	getline(in , str);
	in.close();
	cout << str ;
	
}
