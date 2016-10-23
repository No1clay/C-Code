#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
	set<string> name;
	string key;
	for(int i = 0; i < 6 ; i++) {
		cin >> key;
		name.insert(key);
	}
	set<string>::iterator it;
	it = name.begin();
	while(it != name.end()){
		cout << *it << endl;
		it++;
	}
	return 0;
}

