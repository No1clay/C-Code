#include<iostream>
using namespace std;
int max(int a,int b){
	return (a>b?a:b);
} 
long max(long a,long b){
	return (a>b?a:b);
}
double max(double a,double b){
	return (a>b?a:b);
}
int main(){
	cout<<"The max(2,3)="<<max(2,3); 
	cout<<"The max(55555,55554)="<<max(55555,55554);
	cout<<"The max(2.556613,2.1)="<<max(2.556613,2.1);
	return 0;
}
