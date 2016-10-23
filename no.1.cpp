#include<iostream>
using namespace std;
int main1() {//标准的输入输出流操作 
	int a;
	double f;
	char str[20];
	cout <<"hello，my world！ ";
	cin >> a >> f >> str;
	cout << a<<f<<str;
}

const int i=5;
int fun(const int j){
	cout <<j;
	//j++;使用const修饰参数，可以防止参数被修改 
}
int main(){
	//i++会进行报错，由于常量在程序运行中是无法改变的。 
	int k=5;
	fun(k);
}


