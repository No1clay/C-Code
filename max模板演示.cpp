#include<iostream>
using namespace std;
template <class T>
T max(T &x, T &y){
	return (x>y? x: y);
}
int main(){
	cout << max(3, 4);
	cout << max('c', 'a');
	return 0;
}

