//  Demonstrate insert().

#include <iostream>
#include <string>
using namespace std; 
int main()
{
  string str1("The website address of our university is:");
  string str2("www.xupt.edu.cn"); 
  cout << "Initial strings:\n";
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << "\n\n";  
// demonstrate insert()
  cout << "Insert str1 into str2:\n";
  str2.insert(0,str1);
  str2.insert()
  cout << str2 << "\n\n";
  return 0;
}
/*���н����
Initial strings:
str1: The website address of our university is:
str2: www.xupt.edu.cn

Insert str1 into str2:
The website address of our university is:www.xupt.edu.cn


--------------------------------
Process exited after 0.02643 seconds with return value 0
�밴���������. . . */


 
/*
Ӧ��Ϊ���²��裺
1. �������붯̬�ռ佫Ŀ���ַ�������ַ�������
2.�����������������λ��֮����ַ�����
3.�ڲ���λ�ý�Ҫ������ַ�������
4.����Ŀ��string��ĸ���ֵ
*/ 


