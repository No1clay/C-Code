#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
int main() {
	list<string> listString;
	string keyWord[] = {"�Ĵ�����", "������", "����", "����", "����¡", "����", "���޵���", "ī����"};
	for(int i = 0; i < 8; i++) {
		listString.push_back(keyWord[i]);
	}
	listString.sort();
	list<string>::iterator it;
	it = listString.begin();
	while(it !=  listString.end()){
		cout << *it << endl;
		it++;
	}
	return 0;
}


