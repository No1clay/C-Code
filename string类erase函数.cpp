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
/*���н����
This is an example sentence.
This is an sentence.
This is a sentence.
This sentence.

--------------------------------
Process exited after 0.23 seconds with return value 0
�밴���������. . .
*/ 
/*˼����
erase������ԭ�����£�
��1��string& erase ( size_t pos = 0, size_t n = npos );
��2��iterator erase ( iterator position );
��3��iterator erase ( iterator first, iterator last );
Ҳ����˵�������÷���
��1��erase(pos,n); ɾ����pos��ʼ��n���ַ�������erase(0,1)����ɾ����һ���ַ�
��2��erase(position);ɾ��position����һ���ַ�(position�Ǹ�string���͵ĵ�����)
��3��erase(first,last);ɾ����first��last֮����ַ���first��last���ǵ�������
�ִ���ɾ����ʵ����ͨ���������ַ���:
1.ͨ����ʼɾ���㣬ɾ���ĳ��ȣ�������ֹ��ȷ��Ҫɾ�����ַ�����
2.����ɾ��
3.��ɾ������ַ������¸���string��ָ�� 
4.����Ŀ��string������� 
*/ 
