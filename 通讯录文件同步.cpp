#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;
int main() {
	string name , num;
	map<string, string> phonebook;
	ifstream phonebook1("D://TeachAndTest/testFile/phonebook1.txt");
	if(!phonebook1.is_open()) {
		cout << "Can't open file!" << endl;
	}
	while(!phonebook1.eof()) {
		phonebook1 >> name >> num ;
		phonebook.insert(pair<string, string>(name, num));
	}
	phonebook1.close();
	ifstream phonebook2("D://TeachAndTest/testFile/phonebook2.txt");
	if(!phonebook2.is_open()) {
		cout << "Can't open file!" << endl;
	}
	while(!phonebook2.eof()) {
		phonebook2 >> name >> num ;
		phonebook.insert(pair<string, string>(name, num));
	}
	phonebook2.close();
	ofstream phonebook3("D://TeachAndTest/testFile/phonebook3.txt");
	if(!phonebook3.is_open()) {
		cout << "Can't open file!" << endl;
	}
	map<string, string>::iterator it = phonebook.begin();
	while(it != phonebook.end()) {
		phonebook3 << it->first << " " << it->second << endl;
		it++;
	}
	phonebook3.close();
}
