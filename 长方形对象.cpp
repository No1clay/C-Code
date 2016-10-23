#include<iostream>
using namespace std;
class Rectangle{
	float length;
	float width;
	public:
		void setRectangle(float ll,float ww){
			length=ll;
			width=ww;
		}
		void count(){
			cout <<"The area is "<<length*width;
		}		
};
int main(){
	Rectangle one;
	one.setRectangle(45.22,56.22);
	one.count();
	return 0;
}
