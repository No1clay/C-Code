// replacing in a string
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string base="this is a test string.";
    string str2="n example";
    string str3="sample phrase";
    string str4="useful."; 
    // replace signatures used in the same order as described above:
    // Using positions:                 0123456789*123456789*12345
    string str=base;           // "this is a test string."
    str.replace(9,5,str2);          // "this is an example string." (1)
    str.replace(19,6,str3,7,6);     // "this is an example phrase." (2)
    str.replace(8,10,"just a");     // "this is just a phrase."     (3)
    str.replace(8,6,"a shorty",7);  // "this is a short phrase."    (4)
    str.replace(22,1,3,'!');        // "this is a short phrase!!!"  (5)
    cout << str << '\n';  
}
/*运行结果：
this is a short phrase!!!

--------------------------------
Process exited after 0.02492 seconds with return value 0
请按任意键继续. . .

*/ 
/*
string &replace(int p0, int n0,const char *s);//删除从p0开始的n0个字符，然后在p0处插入串s
string &replace(int p0, int n0,const char *s, int n);//删除p0开始的n0个字符，然后在p0处插入字符串s的前n个字符
string &replace(int p0, int n0,const string &s);//删除从p0开始的n0个字符，然后在p0处插入串s
string &replace(int p0, int n0,const string &s, int pos, int n);//删除p0开始的n0个字符，然后在p0处插入串s中从pos开始的n个字符
string &replace(int p0, int n0,int n, char c);//删除p0开始的n0个字符，然后在p0处插入n个字符c
string &replace(iterator first0, iterator last0,const char *s);//把[first0，last0）之间的部分替换为字符串s
string &replace(iterator first0, iterator last0,const char *s, int n);//把[first0，last0）之间的部分替换为s的前n个字符
string &replace(iterator first0, iterator last0,const string &s);//把[first0，last0）之间的部分替换为串s
string &replace(iterator first0, iterator last0,int n, char c);//把[first0，last0）之间的部分替换为n个字符c
string &replace(iterator first0, iterator last0,const_iterator first, const_iterator last);//把[first0，last0）之间的部分替换成[first，last）之间的字符串
以上是所有replace的函数定义，替换操作的步骤应该为：
1.通过给定的形参确定子串的位置
2.截取要替换的子串之前和之后的子串
3.将替换的子串连接到中间的位置
4.将字符串重新给原对象 
*/
