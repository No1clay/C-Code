#include<iostream>
#include<map>
#include<string> 
using namespace std;
int main(){
	string keyWord[] = {"�Ĵ�����", "123", "����", "124", "����¡", "125", "���޵���", "126"};
	map<string , string> m;
	for(int i = 0 ; i < 8;){
		m.insert(pair<string , string> (keyWord[i] , keyWord[i + 1]));
		i += 2;
	}
	
	string key;
	cout << "Enter a key word :" << endl;
	cin >> key;
	
	map<string , string>::iterator  p;
	p = m.find(key);
	
	if(p != m.end()){
		cout << "Number : " << p->second << endl;
	} else{
		cout << "Error" << endl;
	}
	return 0;
}

