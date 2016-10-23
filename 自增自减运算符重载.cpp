#include<iostream>
using namespace std;
class test{
	int a , b;
	public :
		test(int aa, int bb){
			a = aa;
			b = bb;
		}
		test operator ++(){
			cout << "++ test" << endl;
			++a;
			return *this;
		}
		test operator ++(int){
			cout << "test ++" << endl;
			int aa ;
			aa = a ++;
			return test(aa , b);
		}
		friend test operator --(const test &x){
			cout << "friend -- test" << endl;
			int aa = x.a;
			--aa;
			return test(aa , x.b); 
		}
		friend test operator --(const test &x , int  ){
			cout << "friend test --" << endl;
			int aa = x.a;
			aa--;
			return test(aa , x.b);
		}
		void print(){
			cout << "The num is " << a << " + " << b << "i " << endl;
		}
};
int main(){
	test t1(3 , 6) , t2(3 , 6) , t3(3 , 6) , t4(3 , 6);
	t1++;
	t1.print();
	++t2;
	t2.print();
	--t3;
	t3.print();
	t4--;
	t4.print();
	return 0;
}

