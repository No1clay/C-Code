// concatenating strings
#include <iostream>
#include <string> 
main ()
{
  std::string firstlevel ("cn");
  std::string secondlevel ("edu");
  std::string thirdlevel("xupt");
  std::string scheme ("http://");
  std::string hostname;
  std::string url;
  hostname = "www." + thirdlevel+ '.'+secondlevel + '.' + firstlevel;
  url = scheme + hostname;
  std::cout << url << '\n';
  return 0;
}
/*���н����
 http://www.xupt.edu.cn

--------------------------------
Process exited after 0.2774 seconds with return value 0
�밴���������. . .
*/
/*��C�����е�strcat( )�������бȽϡ�
strcat�Ĳ����������ַ������������ַ�����ֵ���ӵ�һһ��
����c++�ַ���û�н�ֹ����Ϊ��־������ʹ��+�ſ��Ը����
�������ַ�����ʹstring���ʹ�ø��Ӽ�� 
