#include<iostream>
#include<cmath>
using namespace std;
class Point
{
	public:
		Point(double xi,double yi){
			x=xi;
			y=yi;
		}
		void print(){
			cout <<"µã("<<x<<","<<y<<")";
		}
		friend double Distance(Point &a,Point &b); 
		private:
			double x,y;
};
double Distance(Point &a,Point &b){
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return (sqrt(dx*dx+dy*dy)); 
}
int main(){
	Point p1(2.0,3.2),p2(5.33,4.25);
	double d=Distance(p1,p2);
	cout <<"When you found this ,the distance between ";
	p1.print();
	cout<<"and";
	p2.print();
	cout<<"should be "<<d<<endl;
}
