#include<iostream>
using namespace std;
void myterm() {
	cout << "This is my terminater ." << endl;
	exit(1);
}
int main(){
	
	try{
		set_terminate(myterm);
		throw "Exception ...";//
	}catch(int i){
		cout << "test" << endl; 
	}
	return 0;
}
