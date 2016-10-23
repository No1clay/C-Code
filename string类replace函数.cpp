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
/*���н����
this is a short phrase!!!

--------------------------------
Process exited after 0.02492 seconds with return value 0
�밴���������. . .

*/ 
/*
string &replace(int p0, int n0,const char *s);//ɾ����p0��ʼ��n0���ַ���Ȼ����p0�����봮s
string &replace(int p0, int n0,const char *s, int n);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�������ַ���s��ǰn���ַ�
string &replace(int p0, int n0,const string &s);//ɾ����p0��ʼ��n0���ַ���Ȼ����p0�����봮s
string &replace(int p0, int n0,const string &s, int pos, int n);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�����봮s�д�pos��ʼ��n���ַ�
string &replace(int p0, int n0,int n, char c);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0������n���ַ�c
string &replace(iterator first0, iterator last0,const char *s);//��[first0��last0��֮��Ĳ����滻Ϊ�ַ���s
string &replace(iterator first0, iterator last0,const char *s, int n);//��[first0��last0��֮��Ĳ����滻Ϊs��ǰn���ַ�
string &replace(iterator first0, iterator last0,const string &s);//��[first0��last0��֮��Ĳ����滻Ϊ��s
string &replace(iterator first0, iterator last0,int n, char c);//��[first0��last0��֮��Ĳ����滻Ϊn���ַ�c
string &replace(iterator first0, iterator last0,const_iterator first, const_iterator last);//��[first0��last0��֮��Ĳ����滻��[first��last��֮����ַ���
����������replace�ĺ������壬�滻�����Ĳ���Ӧ��Ϊ��
1.ͨ���������β�ȷ���Ӵ���λ��
2.��ȡҪ�滻���Ӵ�֮ǰ��֮����Ӵ�
3.���滻���Ӵ����ӵ��м��λ��
4.���ַ������¸�ԭ���� 
*/
