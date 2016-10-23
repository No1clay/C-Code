#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	map<string , string> phonebook1;
	map<string , string> phonebook2;
	map<string , string> phonebook3;
	string name, num;
	while(true) {
		cin >> name;
		if(name.compare("end") == 0) {
			break;
		} else {
			cin >> num;
			phonebook1.insert(pair<string , string>( name , num));
		}
	}
	while(true) {
		cin >> name;
		if(name.compare("end") == 0) {
			break;
		} else {
			cin >> num;
			phonebook2.insert(pair<string , string>( name , num));
		}
	}

	map<string , string>::iterator one,two,it,dest;
	one = phonebook1.begin();
	two = phonebook2.begin();



	while(one != phonebook1.end()) {
		phonebook3.insert(pair<string , string > (one->first,one->second));
		one++;
	}
	while(two != phonebook2.end()) {
		phonebook3.insert(pair<string , string > (two->first,two->second));
		two++;
	}

	dest = phonebook3.begin();
	while(dest != phonebook3.end()) {
		cout << dest->first << " " << dest->second << endl;
		dest++;
	}	
	return 0;
}

