#include<iostream>
#include<string>
#include<Cstring>
#include<vector>
#include<algorithm>
#include<stdlib.h> 
using namespace std;
const int SIZE = 8;
int main(){
	vector<int> num(SIZE);
	for(int i = 0; i < SIZE; i++){
		num[i] = rand();
	}
	sort(num.begin() , num.end());
	vector<int>::iterator it;
	it = num.begin();
	while(it != num.end()){
		cout << *it << endl;
		it++;
	}
	return 0;
}

