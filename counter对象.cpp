#include<iostream>
using namespace std;
class counter
{
	int value;
	public:
		counter(int number);
		void increment();
		void decrement();
		int getvalue();
		void print();
};
counter::counter(int number){
	value=number;
}
void counter::increment(){
	value++;
}
void counter::decrement(){
	value--;
}
int counter::getvalue(){
	return value;
}
void counter::print(){
	cout<<"The value is "<<value<<endl;
}
int main(){
	int number;
	cout<<"Please intput a intger!"<<endl;
	cin>>number;
	counter one(number);
	counter *two=new counter(number);
	one.increment();
	one.print();
	one.decrement();
	one.print();
	cout<<one.getvalue();
	return 0;
	
}
