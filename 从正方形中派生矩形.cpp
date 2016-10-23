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
	cout<<"正方形Squa1(100)面积为："<<Squa1.GetArea()<<endl;
	cout<<"正方形Squa1(100)面积为："<<objGetArea(&Squa1)<<endl;
	cout<<"长方形Rect(200,300)面积为："<<Rect.GetArea()<<endl;//静态联编 
	cout<<"长方形Rect(200,300)面积为："<<objGetArea(&Rect)<<endl;//动态联编 

	return 0;
}
