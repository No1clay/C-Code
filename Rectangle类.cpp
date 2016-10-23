#include<iostream>
using namespace std;
class Rectangle{
	double width;
	double height;
	public:
		Rectangle(){
			width=height=1;
		}
		Rectangle(double ww,double hh){
			width=ww;
			height=hh;
		}
		double getArea(){
			return (width*height);
		}
		double getPerimeter(){
			return (2*(width+height));
		}
}; 
int main(){
	double ww,hh;
	cout<<"请输入矩形的长和宽"<<endl; 
	cin>>ww>>hh;
	Rectangle rct(ww,hh);
	cout<<"The Area of the rectangle is"<<rct.getArea()<<endl;
	//cout<<rct.getPerimeter()<<endl;
	return 0;
}
