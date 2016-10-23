#include<iostream>
using namespace std;
class complex { //复数类声明
	public:     //外部接口
		complex(double r=0.0,double i=0.0) { //构造函数
			real=r;
			imag=i;
		}
		complex operator + (complex c2) {
			//+重载为成员函数
			double real1 = real + c2.real;
			double imag1 = imag + c2.imag;
			return *new complex(real1, imag1);
		}
		complex operator - (complex c2) {
			//-重载为成员函数
			double real1 = real - c2.real;
			double imag1 = imag - c2.imag;
			return *new complex(real1, imag1);
		}
		void display( ) {
			//输出复数
			cout << real << " + " << imag << " i" << endl;
		}
	private:    //私有数据成员
		double real;   //复数实部
		double imag;   //复数虚部
};
int main() {
	complex complex1(3.5,4.5),complex2(3.5,4.5),complex3(3.5,4.5);
	complex1.display();
	
	complex1 = complex1 + complex2;
	complex1.display();

	complex1 = complex1 - complex3;
	complex1.display();
	
	return 0;
}
