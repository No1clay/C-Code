#include<iostream>
using namespace std;
template<class T , int SIZE>
class Stack{
	T stack[SIZE];
	int pos;
	public:
		Stack(){
			pos = 0;
		}
		~Stack(){
			
		}
		void push(T n){
			if(pos != (SIZE - 1)){
				stack[pos++] = n;
			}else{
				cout << "ջ������" << endl;
			}
			
		}
		T pop(){
			if(pos != 0){
				T temp = stack[--pos];
				return temp;
			}else{
				cout << "ջ���ѿ�" << endl;
			}
		}
};
int main(){
	Stack<int , 90> st1;
	st1.push(33);
	cout << "ջ��Ԫ��Ϊ��" << st1.pop() << endl;
	Stack<char , 90> st2;
	st2.push('c');
	cout << "ջ��Ԫ��Ϊ��" << st2.pop() << endl;
	Stack< double , 90> st3;
	st3.push(4.5);
	cout << "ջ��Ԫ��Ϊ��" << st3.pop() << endl;
	return 0;
}
