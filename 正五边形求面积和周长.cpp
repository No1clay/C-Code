#include<iostream>
#include<math.h>
using namespace std;
const double pi=3.141592653;
class shape {
		double a;
	public:
		void setA(double aa) {
			a=aa;
		}
		double getArea() {
			double S=0.25*a*a*sqrt(25+10*sqrt(5));
			return S;
		}
		double getPerimeter() {
			double R=a/(2*sin(36/180.0*pi));
			return R;
		}
};
int main() {
	double a;
	cin>>a;
	shape one;
	one.setA(a);
	cout<<one.getArea()<<endl;
	cout<<one.getPerimeter();
	return 0;
}
