#include<iostream>
using namespace std;
int main(){
	/*
	cout.setf(ios::showpos);//在输出的非负数的前边加+号 
	cout.setf(ios::scientific);//以科学计数法的形式显示浮点数 
	cout << 1999 << " " << 3.1415926 << endl;
	
	cout.setf(ios::uppercase);//十六进制中显示0X，科学技术法中显示E 
	cout << 1999 << " " << 3.1415926 << endl;
	
	cout.setf(ios::fixed);//以小数的形式显示浮点数（默认的格式状态） 
	cout << 1999 << " " << 3.1415926 << endl;
	*/
	cout << showpos << scientific << 1999 << " " << 3.1415926 << endl; 
	cout << uppercase << 1999 << " " << 3.1415926 << endl; 
	cout << fixed << 1999 << " " << 3.1415926 << endl; 
	return 0;
} 
