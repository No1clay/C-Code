#include<iostream>
using namespace std;
class Triangle
{
	double width;
	double height;
	public:
		void setSize(double w,double h)
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
	Triangle t1;
	t1.setSize(3,4);
	cout<<"The area is:"<<t1.area()<<endl;
	return 0; 
}
