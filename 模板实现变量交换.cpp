#include<iostream>
using namespace std;
template <class T>
void swap1(T &a , T &b){
	T temp;
	temp = a ;
	a = b;
	b = temp;
} 
int main(){
	int i ,j;
	cin >> i >> j;
	char a , b;
	cin >> a >> b;
	swap1(i , j);
	cout << i << " " << j << endl; 
	swap1(a , b);
	cout << a << " " << b;
	return 0;
}

