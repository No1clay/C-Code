#include<iostream>
using namespace std;
class test{
	int a , b;
	public :
		test(int aa = 0 , int bb = 0){
			a = aa;
			b = bb;
		}
		test operator ()(int aa , int bb){
			a = a + aa;
			b = b + bb;
		}
		void print(){
			cout << "The num is " << a << " + " << b << "i " << endl;
		}
};
int main(){
	test t1, t2(3 , 5);
	t1.print();
	t2.print();
	t1(3 , 5);
	t1.print();
	return 0;
}

