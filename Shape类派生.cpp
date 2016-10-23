#include<iostream>
using namespace std;
class Shape{
	public :
		double GetArea(){
			
		}
}; 
class Square : public Shape{
	double a ;
	public:
		Square(double aa){
			a = aa;
		} 
		double GetArea(){
			return a * a;
		}
};
class Triangle :public Shape{
	double d , h ;
	public:
		Triangle(double dd , double hh){
			d = dd;
			h = hh;
		}
		double GetArea(){
			return (d * h )/2.0;
		}
};
int main(){
	double x ,y , z;
	cin >> x >> y >> z;
	Square one(x );
	Triangle two(y , z);
	cout << "The area of the Square is " << one.GetArea() << endl;
	cout << "The area of the Triangle is " << two.GetArea() << endl;
	return 0;
}

