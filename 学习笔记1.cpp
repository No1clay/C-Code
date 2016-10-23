//my first cpp to display a message

//#include<iostream>//最应该使用的方式 
//int main()
//{
//	std::cout << "come up and C++ me some time.";
//	std::cout << std::endl;
//	std::cout << "You won't regret it!" << std::endl;
//	return 0;
//}

//#include<iostream>//使用命名空间里所有字符 
//using namespace std;
//int main()
//{
//	cout << "come up and C++ me some time.";
//	cout << endl;
//	cout << "You won't regret it!" << endl;
//	return 0;
//}

#include<iostream>//仅使用这两个字符 

using std::cout;
using std::endl;

int main()
{
	cout << "come up and C++ me some time.";
	cout << endl;
	cout << "You won't regret it!" << endl;
	return 3;
}
