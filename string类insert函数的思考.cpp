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
/*运行结果：
Initial strings:
str1: The website address of our university is:
str2: www.xupt.edu.cn

Insert str1 into str2:
The website address of our university is:www.xupt.edu.cn


--------------------------------
Process exited after 0.02643 seconds with return value 0
请按任意键继续. . . */


 
/*
应该为以下步骤：
1. 重新申请动态空间将目标字符串类的字符串保存
2.申请迭代器，将插入位置之后的字符后移
3.在插入位置将要插入的字符串插入
4.更新目标string类的各种值
*/ 


