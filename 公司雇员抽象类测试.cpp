#include <iostream>
using namespace std;
class Base {
	public:
		virtual void f(float x) {
			cout << "Base::f(float) "  << x << endl;
		}
		void g(float x) {
			cout << "Base::g(float) "  << x << endl;
		}
		void h(float x) {
			cout << "Base::h(int) "  << x << endl;
		}
};

class Derived : public Base {
	public:
		void f(int x) {
			cout << "Derived::f(int) "  << x << endl;
		}
		void g(int x)  {
			cout << "Derived::g(int) "  << x << endl;
		}
		void h(float x) {
			cout << "Derived::h(float) "  << x << endl;
		}
};

int main() {
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;

	//没出现隐藏的情况
	pb->f(3.14f);             //Derived::f(float) 3.14
	pd->f(3.14f);             //Derived::f(float) 3.14

	//出现隐藏的情况 1
	pb->g(3.14f);             //Base::g(float) 3.14
	pd->g(3.14f);             //Derived::g(int)  3       (surprise!)

	//出现隐藏的情况 2
	pb->h(3.14f);             //Base::h(float) 3.14         (surprise!)
	pd->h(3.14f);             //Derived::h(float)  3.14
	system("pause");
	return 0;
}
