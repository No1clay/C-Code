#include<iostream>
using namespace std;
class Base{
	public:
		virtual void show(){
			cout << "���ǻ���" << endl;
		}
};
class Derived : public Base{
	public:
		void show(){
			cout << "����������" << endl; 
		}
};
int main(){
	Derived one;
	Base *pbase = &one;
	Derived *pderived = &one;
	pbase->show();
	pderived->show();
	return 0;
}

