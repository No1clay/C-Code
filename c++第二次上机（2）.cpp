#include<iostream>
using namespace std;
void sqr_it (int *i);//function prototype 函数原型
int main(){
	int x;
	x=10;
	sqr_it(&x);
	//sqr_it (x);//comiling time error :type mismatch 类型不匹配
	cout <<"The square x is "<<x<<"\n";
	return 0; 
} 
void sqr_it (int *i){
	*i=(*i)*(*i);
}
