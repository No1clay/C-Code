#include<iostream>
using namespace std;
int max(int &x,int &y);//������������ʹ��
float max(float &x,float &y);
long int max(long int &x,long int &y);
int fun3() {//�������͵Ŀռ��ʱ����Խ�����󣬵������ַ�����ʱ��û��Խ��������֣����� 
	/*char *p = new char;
	int i;
	//p = new char;
	for (i = 0; i <25; i++) {
		//p[i] = i;
		p[i]=char (i+'a');
	}

	for (i = 0; i < 25; i++) {
		cout<<p[i]<<" ";
	}
	cout<<endl;
	delete []p;
	return 0;*/
	int *p = new int[3];
	for (int i = 0; i <13; i++) {
		p[i]=i;
	}

	for (int i = 0; i < 12; i++) {
		cout<<p[i]<<" ";
	}
	cout<<endl;
	delete []p;
	return 0;
}
int main() {
	cout<<max(3.1,2.9)<<endl;
	cout <<"3"<<endl;
	char *name;
	name=new char[30];
	cin.getline(name,29);
	cout <<name<<endl; 
	delete name;
	name=NULL;
	cout <<name<<endl; 
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
