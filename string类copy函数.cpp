// string::copy
#include <iostream>
#include <string>
using namespace std;
//int string::copy(char* s, int len, int pos = 0) const ����ԭ��
int main ()
{
  char ChangAn[20];
  string str ("Xi'an University of Post & Telecommunications");
  int length = str.copy(ChangAn,10,6);
  ChangAn[length]='\0';
  cout << "ChangAn contains: " << ChangAn << '\n';
  return 0;
}
/*���н����
ChangAn contains: University

--------------------------------
Process exited after 0.02551 seconds with return value 0
�밴���������. . .

*/ 
/*��ͬ��
strcpy()��c����������һ���ַ�����ȫ��ֵ����һ���ַ�����������ֹ���� 
copy()����ַ��������ݸ��ƻ�д����е�c_string�� �ַ������ڡ���û��
��ֹ���Ĵ��� ����������C++�ַ���������'/0'��β��*/ 

