#include<iostream>
using namespace std;
int main1() {//��׼��������������� 
	int a;
	double f;
	char str[20];
	cout <<"hello��my world�� ";
	cin >> a >> f >> str;
	cout << a<<f<<str;
}

const int i=5;
int fun(const int j){
	cout <<j;
	//j++;ʹ��const���β��������Է�ֹ�������޸� 
}
int main(){
	//i++����б������ڳ����ڳ������������޷��ı�ġ� 
	int k=5;
	fun(k);
}


