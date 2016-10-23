// string::find

#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string str ("There are two needles in this haystack with needles.");
	string str2 ("needle");
	// different member versions of find in the same order as above:
	int found = str.find(str2);
	if (found!=-1)
		cout << "first 'needle' found at: " << found << '\n';
	found=str.find("needles are small",found+1,6);
	if (found!=-1)
		cout << "second 'needle' found at: " << found << '\n';
	found=str.find("haystack");
	if (found!=-1)
		cout << "'haystack' also found at: " << found << '\n';
	found=str.find('.');
	if (found!=-1)
		cout << "Period found at: " << found << '\n';
	// let's replace the first needle:
	str.replace(str.find(str2),str2.length(),"preposition");
	cout << str << '\n';
	return 0;
}
/*运行结果：
first 'needle' found at: 14
second 'needle' found at: 44
'haystack' also found at: 30
Period found at: 51
There are two prepositions in this haystack with needles.

--------------------------------
Process exited after 0.02145 seconds with return value 0
请按任意键继续. . .
*/


/*实现
#include<iostream>
#include<string.h>
using namespace std;
const int npos=-1;
class SString {
		char *content;
		int len;
	public :
		SString(char *str) {
			content=new char[strlen(str)+1];
			strcpy(content,str);
			len=strlen(content);
		}
		int length() {
			return len;
		}
		void print() {
			cout<<content;
		}
		char *getContent() {
			return content;
		}
		int StrIndex(int start_pos,SString B);
};
int SString::StrIndex(int start_pos,SString B) {
	int pos=npos;
	int *next,*nextval;
	next=new int[B.length()];
	nextval=new int[B.length()];

	
	int i;
	char *str=new char[B.length()+2];
	strcpy(&str[1],B.getContent());

	
	int j=1;
	int k=0;
	next[1]=0;
	while(j<B.length()) {
		if(k==0||str[j]==str[k]) {
			++j;
			++k;
			next[j]=k;
		} else {
			k=next[k];
		}
	}
	
	j=2;
	k=0;
	nextval[1]=0;
	while(j<=B.length()) {
		k=next[j];
		if(str[j]==str[k]) {
			nextval[j]=nextval[k];
		} else {
			nextval[j]=next[j];
		}
		j++;
	}

	char *deststr=content;
	i=start_pos;
	j=1;
	while(pos==npos&&i<=len){
		if(deststr[i]==str[j]){
			i++;
			j++;
		}
		else{
			i++;
			j=nextval[j]+1;
		}
		if(j==B.length()+1){
			pos=i-1;
		}
	}
	
	
	delete []str;
	delete []next;
	delete []nextval;
	return pos;
}
int main() {
	char str[20];
	cin>>str;
	SString one(str);
	cin>>str;
	SString two(str);
	cout<<one.StrIndex(0,two);
} 
*/ 
 
