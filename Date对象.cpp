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
}; // const �Ǻ���ԭ�͵�һ����ɲ��֣�����ں������岿��ҲҪ�� const �ؼ��֡�
inline int Date::year( ) const {
	//return y++;
	return y; 
}
int main(){
	return 0;
}
