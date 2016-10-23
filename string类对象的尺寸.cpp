// comparing size, length, capacity and max_size
#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string str ("Test string");
	cout << "size: " << str.size() << "\n";
	cout << "length: " << str.length() << "\n";
	cout << "capacity: " << str.capacity() << "\n";
	cout << "max_size: " << str.max_size() << "\n";
	return 0;
}
/*运行结果： 
size: 11
length: 11
capacity: 11
max_size: 4611686018427387897

--------------------------------
Process exited after 0.2367 seconds with return value 0
请按任意键继续. . .*/ 
 
/*string类的对象是通过字符串指针进行存储的，因为在没有对字符串进行赋值的时候，不能访问
string[0] 的空间，很显然没有存储东西的string是没有分配空间的，而进行赋值的时候会在堆上
自动分配空间*/
