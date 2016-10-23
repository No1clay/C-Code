#include<iostream>
using namespace std;
int max(int &x,int &y);//函数名的重载使用
float max(float &x,float &y);
long int max(long int &x,long int &y);
int fun3() {//申请整型的空间的时候有越界现象，但是在字符串的时候没有越界现象出现？？？ 
	char *p = new char[10];
	int i;
	//p = new char;
	for (i = 0; i <100; i++) {
		//p[i] = i;
		p[i]=char (i+'a');
	}

	for (i = 0; i < 100; i++) {
		cout<<p[i]<<" ";
	}
	cout<<endl;
	delete []p;
	return 0;
}
int main() {
	cout<<max(3.1,2.9)<<endl;
	cout <<"3"<<endl;
	/*
	char *p;
	p=new char[3];
	cin>>p;
	cout<<"My Name Is " <<p<<endl;
	delete p;
	cout <<p<<endl;
	*/
	fun3();
	return 0;

}
int max(int &x,int &y) {
	return (x>y)?x:y;
}
float max(float &x,float &y) {
	return (x>y)?x:y;
}
long int max(long int &x,long int &y) {
	return (x>y)?x:y;
}
