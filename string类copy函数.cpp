// string::copy
#include <iostream>
#include <string>
using namespace std;
//int string::copy(char* s, int len, int pos = 0) const 函数原型
int main ()
{
  char ChangAn[20];
  string str ("Xi'an University of Post & Telecommunications");
  int length = str.copy(ChangAn,10,6);
  ChangAn[length]='\0';
  cout << "ChangAn contains: " << ChangAn << '\n';
  return 0;
}
/*运行结果：
ChangAn contains: University

--------------------------------
Process exited after 0.02551 seconds with return value 0
请按任意键继续. . .

*/ 
/*不同：
strcpy()是c函数，它将一个字符串完全赋值给另一个字符串，包含结止符。 
copy()则把字符串的内容复制或写入既有的c_string或 字符数组内。并没有
结止符的存在 ，这是由于C++字符串并不以'/0'结尾。*/ 

