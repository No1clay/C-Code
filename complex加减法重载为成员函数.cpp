#include<iostream>
using namespace std;
class complex { //����������
	public:     //�ⲿ�ӿ�
		complex(double r=0.0,double i=0.0) { //���캯��
			real=r;
			imag=i;
		}
		complex operator + (complex c2) {
			//+����Ϊ��Ա����
			double real1 = real + c2.real;
			double imag1 = imag + c2.imag;
			return *new complex(real1, imag1);
		}
		complex operator - (complex c2) {
			//-����Ϊ��Ա����
			double real1 = real - c2.real;
			double imag1 = imag - c2.imag;
			return *new complex(real1, imag1);
		}
		void display( ) {
			//�������
			cout << real << " + " << imag << " i" << endl;
		}
	private:    //˽�����ݳ�Ա
		double real;   //����ʵ��
		double imag;   //�����鲿
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
