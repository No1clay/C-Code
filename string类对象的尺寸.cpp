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
/*���н���� 
size: 11
length: 11
capacity: 11
max_size: 4611686018427387897

--------------------------------
Process exited after 0.2367 seconds with return value 0
�밴���������. . .*/ 
 
/*string��Ķ�����ͨ���ַ���ָ����д洢�ģ���Ϊ��û�ж��ַ������и�ֵ��ʱ�򣬲��ܷ���
string[0] �Ŀռ䣬����Ȼû�д洢������string��û�з���ռ�ģ������и�ֵ��ʱ����ڶ���
�Զ�����ռ�*/
