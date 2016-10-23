#include<iostream>
#include<string>
using namespace std;
class Student{
	int number;
	string name;
	float score;
	public:
		Student(int number1 = 0 ,string name1 = "noname" , float score1 = 0){
			number = number1;
			name = name1;
			score = score1;
		}
		void modify(float score1){
			score = score1;
		}
		friend istream &operator >> (istream &input, Student &stu){
			cout << "Please input a student's number, name, and score:\n";
			input >> stu.number >> stu.name >> stu.score;
			return input;
		}
		friend ostream &operator << (ostream &output , Student &stu){
			output << "number:" << stu.number << " name:" << stu.name << " score:" << stu.score << endl;
			return output;
		}
};
int main(){
	Student stu1;
	cout << stu1;
	cin >> stu1;
	cout << stu1;
	return 0;
} 
