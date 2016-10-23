#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
	string str1("This is a test £¡");
	string str2("ABCDEFG");
	
	cout << "The String is :" << endl;
	cout << "str1 :" << str1 << endl;
	cout << "str2 :" << str2 << endl;
	
	cout << "Insert str2 into str1 :" << endl;
	str1.insert( 5 , str2);
	cout << str1 << endl;
	
	cout << "Remove 7 chars from str1 :" << endl;
	str1.erase(5 , 7);
	cout << str1 << endl;
	
	cout << "Replace 2 chars in str1 with str2 : " << endl; 
	str1.replace(5 , 2 , str2);
	cout << str1 << endl;
	return 0;
}

