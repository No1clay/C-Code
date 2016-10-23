#include<iostream>
using namespace std;
class Circle{
	float radius;
	static int count;
	public:
		Circle(float r){
			radius++;
			++count;
		}
		~Circle(){
			--count;
		}
		static int num(){
			return count;
		}
};
int Circle::count=0;
int main(){
	Circle c(5.6);
	cout<<"The count of the circle is "<<c.num(); 
	return 0;
}
