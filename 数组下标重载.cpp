#include<iostream>
#include<Cstring>
using namespace std;
class words{
	char *str;
	public:
		words(char *s){
			str = new char[strlen(s) + 1];
			strcpy(str , s);
		}
		~words(){
			delete []str;
		}
		void print(){
			cout << str << endl;
		}
		char &operator [ ] (int a){
			return *(str + a + 1);
		}
};
int main(){
	words word("achina");
	for(int i = 0 ; i < strlen("achina") ; i++){
		cout << word[i] ;
	}
	return 0;
}

