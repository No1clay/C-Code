#include<iostream>
using namespace std;
class Base{
	public:
		virtual void show(){
			cout << "这是基类" << endl;
		}
};
class Derived : public Base{
	public:
		void show(){
			cout << "这是派生类" << endl; 
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

