#include<iostream>
using namespace std;
class Triangle
{
	double width;
	double height;
	public:
	Triangle(double w,double h)	
	{
		width=w;
		height=h;
	} 
	double area()
	{
		return width*height/2;
	}
};
int main()
{
	Triangle t2(4,5);
	cout<<"The area is:"<<t2.area()<<endl;
	return 0;
}

