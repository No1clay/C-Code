#include<iostream>
using namespace std;
class time{
	long sec = 0 , min = 0 , hour = 0;
	public :
		time(long s){
			hour = s/3600;
			min = (s - hour*3600)/60;
			sec = s - hour*3600 - min*60;
		}
		time(long m , long s){
			hour = m/60;
			min = m - hour * 60;
			sec = s;
		}
		time(long h, long m , long s){
			hour = h;
			min = m;
			sec = s;
		}
		void print(){
			cout << hour << ":" << min << ":" << sec << endl;
		}
};
class num{
	double long number;
	public :
		num(double long n){
			number = n;
		}
		operator int(){
			return (int)number;
		} 
		operator double (){
			return (double )number;
		}
}; 
int main(){
	time p1(0), p2(0) ,p3(0);
	p1 = 1800;
	p2 = time(666 , 33);
	p3 = time(336 , 33 , 3);
	p1.print();
	p2.print();
	p3.print();
	
	
	num n1 = 36.5555453366;
	int a = n1;
	double b = n1;
	//float c = n1; error
	cout << "int number is " << a << endl;
	cout << "double number is " << b << endl;
	return 0;
}

