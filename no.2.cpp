#include<iostream>
using namespace std;
int fun(){
	char str[20]="123456789";
	char str2[20]="987654321";
	
	
	const char *pc=str;
	pc=str2;
	//pc[2]='0';pcΪָ���ַ���������ָ�롣 
	cout <<pc<< endl;
	
	
	char const *pc2=str;
	pc2=str2;
	//pc2[2]='0';pc2ָ�����ַ�����ָ�롣 
	cout << pc2<< endl;
	
	
	char *const pc3=str;
	//pc3=str2;pc3Ϊָ���ַ����ĳ���ָ�룬ָ���ַ���ܹ����иı� 
	pc3[2]='a';
	cout << pc3 <<endl;
	
	return 0;
}
inline int max(int &a,int &b){//�����������ÿռ任ȡʱ�䣬���ٵ��ô��������š� 
	if(a>b)	return a;
	else return b;
}
int main(){
	fun();
	int a=2,b=3;
	cout<<max(b,a)<<endl;
	return 0;
}
