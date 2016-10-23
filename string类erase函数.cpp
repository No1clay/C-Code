// string::erase

#include <iostream>
#include <string>
using namespace std;
int main ()
{
  std::string str ("This is an example sentence.");
  std::cout << str << '\n'; // "This is an example sentence."
  str.erase (10,8); //            ^^^^^^^^
  std::cout << str << '\n';// "This is an sentence."
  str.erase (str.begin()+9);//        ^
  std::cout << str << '\n';// "This is a sentence."
  str.erase (str.begin()+5, str.end()-9);  // ^^^^^
  std::cout << str << '\n';// "This sentence."
  return 0;
}
/*运行结果：
This is an example sentence.
This is an sentence.
This is a sentence.
This sentence.

--------------------------------
Process exited after 0.23 seconds with return value 0
请按任意键继续. . .
*/ 
/*思考：
erase函数的原型如下：
（1）string& erase ( size_t pos = 0, size_t n = npos );
（2）iterator erase ( iterator position );
（3）iterator erase ( iterator first, iterator last );
也就是说有三种用法：
（1）erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
（2）erase(position);删除position处的一个字符(position是个string类型的迭代器)
（3）erase(first,last);删除从first到last之间的字符（first和last都是迭代器）
字串的删除其实就是通过上述三种方法:
1.通过开始删除点，删除的长度，或者起止点确定要删除的字符内容
2.进行删除
3.将删除后的字符串重新赋给string类指针 
4.更新目标string类的数据 
*/ 
