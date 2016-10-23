#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	map<string , string> m;
	string name, num;
	while(true) {
		cin >> name;
		if(name.compare("end") == 0) {
			break;
		} else {
			cin >> num;
			m.insert(pair<string , string>( name , num));
		}
	}
	string key;
	cin >> key;

	map<string , string>::iterator  p;
	p = m.find(key);

	if(p != m.end()) {
		cout << p->second << endl;
	} else {
		cout << "Ã»ÕÒµ½¡£" << endl;
	}

	return 0;
}

