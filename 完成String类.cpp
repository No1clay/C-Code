#include<iostream>
#include<Cstring>
using namespace std;
class String {
		char *m_data;
		int length;
	public:
		String(const char *str = NULL) {
			m_data = new char[strlen(str) + 1];
			strcpy(m_data , str);
			length = strlen(str);
		}
		String(const String &other) {
			m_data = new char[other.length + 1];
			strcpy(m_data , other.m_data);
			length = other.length;
		}
		~String(void) {
			length = 0;
			delete []m_data;
		}
		String &operator = (char *str) {
			delete []m_data;
			m_data = new char[strlen(str) + 1];
			strcpy(m_data , str);
			length = strlen(str);
			return *this;
		}
		String &operator = (const String &other) {
			delete []m_data;
			m_data = new char[other.length + 1];
			strcpy(m_data , other.m_data);
			length = other.length;
			return *this;
		}
		int operator == (String &other) {
			return (strcmp(m_data, other.m_data));
		}
		int operator ==(char *str){
			return (strcmp(m_data, str));
		}
		void print(){
			cout << "The content is " << m_data << endl;
			cout << "Size is " << length << endl;
		}
};
int main() {
	char str[20] = "test"; 
	String str1("HelloWorld") ,str2(str1) ,str3(" ") , str4("test"); 
	str3 = str1;
	str3.print();
	str3 = str;
	str3.print();
	cout << (str4 == str) << endl;
	cout << (str1 == str2) << endl;
	return 0;
}

