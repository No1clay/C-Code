#include<iostream>
using namespace std;

const int model=90;//model is a const
const int v[]={1,2,3,4};//v[i] is a const
const int x;//error:no initalizer
void f()
{
	model=200;//error
	v[2]++;//error
}
//ÐÞ¸ÄÒ»£º
/*int model=90;
int v[]={1,2,3,4};
const int x=50;
void f(){
	model=200;
	v[2]++;
	cout<<"The model="<<model<<endl<<"The v[2]= "<<v[2]<<endl;
} 
int main(){
	f();
	return 0;
}*/
