#include<iostream>
using namespace std;
class A{
	public:
		static int coutA;
		A(int n){
			coutA++;
			x = n;
			cout << "constructing Function of Based class A" << endl;
			cout << "It's " << coutA << "class A" << endl;
			cout << "The x is " << x << endl << endl;			
		}
		~A(){
			cout << "destructing Function of Based class A" << endl;
			cout << "It's " << coutA << "class A" << endl;
			cout << "The x is " << x << endl << endl;	
		}
		void showx (){
			cout << x << endl;
		}
		private:
			int x;
};
class B: public A{
	private:
		A a;
		public:
			B(int n) :A(n) ,a(n)
			{
				cout << "constructing Function of Derived class B" << endl;
			}
			~B(){
				cout << "destructing Function of Derived class B"<< endl;
			}
};
int A::coutA = 0;
int main(){
	B b(5);
	b.showx();
	return 0;
}

