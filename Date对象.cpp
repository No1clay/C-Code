#include<iostream>
using namespace std;
class Date {
		int d, m, y;
	public:
		int day( ) const {
			return d;
		}  
		int month( ) const {
			return m;
		}  
		int year( ) const;  // ...
}; // const 是函数原型的一个组成部分，因此在函数定义部分也要带 const 关键字。
inline int Date::year( ) const {
	//return y++;
	return y; 
}
int main(){
	return 0;
}
