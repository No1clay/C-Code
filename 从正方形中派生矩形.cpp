#include<iostream>
using namespace std;
class Square {
	protected:
		int edge;
	public:
		Square(int edg) {
			edge = edg;
		}
		virtual double GetArea() {
			double result;
			result = (edge * edge);
			return result;
		}
};
double objGetArea(Square* base);
class Rectangle :public Square {

	protected:
		int length;
	public :
		Rectangle(int edg, int leng):Square(edg) {
			length = leng;
		}
		double GetArea() {
			double result;
			result = length * edge;

			return result;
		}
};

double objGetArea(Square * obj) {
	return obj->GetArea();
}
int main() {
	Square  Squa1(100);
	Rectangle Rect(200,300);
	cout<<"������Squa1(100)���Ϊ��"<<Squa1.GetArea()<<endl;
	cout<<"������Squa1(100)���Ϊ��"<<objGetArea(&Squa1)<<endl;
	cout<<"������Rect(200,300)���Ϊ��"<<Rect.GetArea()<<endl;//��̬���� 
	cout<<"������Rect(200,300)���Ϊ��"<<objGetArea(&Rect)<<endl;//��̬���� 

	return 0;
}
