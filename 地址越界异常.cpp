#include<iostream>
using namespace std;
int main(){
	int a[10];
	for(int i = 0 ; i < 10; i ++){
		a[i] = i;
	}
	for(int i = 0 ; i < 26; i ++){
		try{
			if(i == 10){
				throw i;
			}else{
				cout << "a[" << i <<"] :" << a[i] << endl;
			}
		}catch(int w){
			cout << "Address cross-border" << endl; 
			break;
		}
	}
}
