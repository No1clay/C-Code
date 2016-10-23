#include<iostream>
using namespace std;
class complex{
	double real;
	double imag;
	public:
		complex(){
			real = 0;
			imag = 0;
		}
		/*complex(double i){
			real = i;
			imag = 0;
		}*/
		complex(double r , double i){
			real = r;
			imag = i;
		}
		friend complex operator+(int c2 , complex &c1){
			double r = c1.real + c2;
			double i = c1.imag;
			return complex(r, i);
		}
		/*complex operator+(double i){
			double r = real + i ;
			return complex(r , imag);
		}*/
		void print(){
			cout << real << endl;
			cout << imag << endl;
		}
};
int main(){
	const double j = 3.4;
	printf("%p",&j);
	/*complex c1(1 , 2);
	complex c2;
	
	c2 = 3 + c1;*/
	double i = 3.4;
	printf("%p\n" , i );
	printf("%p\n" , &i );
	printf("%p" , 3.4);
	return 0;
}

