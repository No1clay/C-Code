#include<iostream>
using namespace std;
int fun(){
	char str[20]="123456789";
	char str2[20]="987654321";
	
	
	const char *pc=str;
	pc=str2;
	//pc[2]='0';pc为指向字符串常量的指针。 
	cout <<pc<< endl;
	
	
	char const *pc2=str;
	pc2=str2;
	//pc2[2]='0';pc2指向常量字符串的指针。 
	cout << pc2<< endl;
	
	
	char *const pc3=str;
	//pc3=str2;pc3为指向字符串的常量指针，指针地址不能够进行改变 
	pc3[2]='a';
	cout << pc3 <<endl;
	
	return 0;
}
inline int max(int &a,int &b){//内联函数利用空间换取时间，减少调用带来的困扰。 
	if(a>b)	return a;
	else return b;
}
int main(){
	fun();
	int a=2,b=3;
	cout<<max(b,a)<<endl;
	return 0;
}
