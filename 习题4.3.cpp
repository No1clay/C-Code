#include<iostream>
using namespace std;
class myclass{
	int a,b;
	public:
		void set(int i,int j){
			a=i;
			b=j;
		}
		void show(){
			cout<<a<<' '<<b<<endl;
		}
};
class yourclass{
	int a,b;
	public:
		void set(int i,int j){
			a=i;
			b=j;
		}
		void show(){
			cout<<a<<' '<<b<<endl;
		}
};
int main(){
	myclass obj1,obj3;
	yourclass obj2;
	obj1.set(10,4);
	obj3=obj1;
	obj2=obj1;
	obj1.show();
	obj2.show();
	obj3.show();
	return 0;
}
