#include<iostream>
using namespace std;
void sqr_it (int *i);//function prototype ����ԭ��
int main(){
	int x;
	x=10;
	sqr_it(&x);
	//sqr_it (x);//comiling time error :type mismatch ���Ͳ�ƥ��
	cout <<"The square x is "<<x<<"\n";
	return 0; 
} 
void sqr_it (int *i){
	*i=(*i)*(*i);
}
