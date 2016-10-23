#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
int main() {
	list<string> listString;
	string keyWord[] = {"澳大利亚", "西班牙", "荷兰", "智利", "喀麦隆", "巴西", "克罗地亚", "墨西哥"};
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


