#include<iostream>
using namespace std;
int main(){
	/*
	cout.setf(ios::showpos);//������ķǸ�����ǰ�߼�+�� 
	cout.setf(ios::scientific);//�Կ�ѧ����������ʽ��ʾ������ 
	cout << 1999 << " " << 3.1415926 << endl;
	
	cout.setf(ios::uppercase);//ʮ����������ʾ0X����ѧ����������ʾE 
	cout << 1999 << " " << 3.1415926 << endl;
	
	cout.setf(ios::fixed);//��С������ʽ��ʾ��������Ĭ�ϵĸ�ʽ״̬�� 
	cout << 1999 << " " << 3.1415926 << endl;
	*/
	cout << showpos << scientific << 1999 << " " << 3.1415926 << endl; 
	cout << uppercase << 1999 << " " << 3.1415926 << endl; 
	cout << fixed << 1999 << " " << 3.1415926 << endl; 
	return 0;
} 
