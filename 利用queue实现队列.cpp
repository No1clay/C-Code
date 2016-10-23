#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	queue<float> sq;
	for(int i = 0; i < 15 ; i++) {
		sq.push(rand()/3.1);
	}
	cout << "The number is :" << endl;
	for(int i = 0; i <  15; i++) {
		cout << i << " : " << sq.front() << endl; 
		sq.pop();
	}


	return 0;
}

