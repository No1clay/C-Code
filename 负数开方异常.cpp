#include<iostream>
#include<Cmath>
using namespace std;
void SqrtX(float x) {
	try {
		if(x < 0) {
			throw x;
		}
		cout << "The sqrt of " << x << " is " << sqrt(x) << endl;
	}
	catch(float w){
		cout << "The number " << w << " is small than zero !" << endl;
	}
}
int main(){
	float x;
	cin >> x;
	SqrtX(x);
}
