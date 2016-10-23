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
/*运行结果：
 http://www.xupt.edu.cn

--------------------------------
Process exited after 0.2774 seconds with return value 0
请按任意键继续. . .
*/
/*与C语言中的strcat( )函数进行比较。
strcat的参数是两个字符串，将两个字符串的值连接到一一起
由于c++字符类没有结止符作为标志，所以使用+号可以更简洁
的连接字符串，使string类的使用更加简洁 
