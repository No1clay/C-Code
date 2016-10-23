#include<iostream>
#include<Cstring>
using namespace std;
class employee {
	protected:
		char *name;//����
		int individualEmpNo;//���˱��
		int grade;//����
		float accumPay;//��н�ܶ�
		static int employeeNo;//����˾ְԱ��
	public:
		employee() {
			//���캯��
			individualEmpNo = employeeNo ++;//Ա�����
			char name1[100];
			cout << "������"<< individualEmpNo << "��Ա�������֣�" << endl << endl;
			cin >> name1;
			name = new char [strlen(name1 ) + 1];
			strcpy(name , name1);
			grade = 1;//�����ֵΪ1
			accumPay = 0.0; //��н��ʼΪ0
		}
		~employee() { //��������
			delete [] name;
		}
		void pay() {

		}//������н
		void promote(int inc) { //��������
			grade = grade + inc;
		}
		void displayStatus();//��ʾ��Ա��Ϣ
};




int employee::employeeNo = 1;
class technician :public employee { //������Ա
	private:
		float hourlyRate;//ÿСʱн��
		int workHours;//���¹�����
	public:
		technician() {
			hourlyRate = 100;//ÿСʱ100Ԫ
		}
		void Pay() {
			cout << "�𾴵�" << name << ", " << individualEmpNo << "�Ź�Ա" << endl; 
			cout << "���¹���ʱ�� :" << endl;
			cin >> workHours;
			accumPay = workHours * hourlyRate;
			cout << "������Ա:" << name <<"\t��ţ�"
			     << individualEmpNo << endl
			     <<"���¹��ʣ�" << accumPay <<"Ԫ" << endl << endl;
		}
		void displayStatus() {
			cout << "������Ա��" << name << "\t��ţ�"
			     << individualEmpNo << endl <<"����"
			     << grade << endl << "���¹��ʣ�" << accumPay <<endl<<endl;
		}
};

class manager : virtual public employee {
	protected:
		float monthlyPay;
	public:
		manager() {
			monthlyPay = 9000;
		}
		void Pay() {
			accumPay = monthlyPay;
			cout << "����:" << name <<"\t��ţ�"
			     << individualEmpNo << endl
			     <<"���¹��ʣ�" << accumPay <<"Ԫ" << endl<< endl;
		}
		void displayStatus() {
			cout << "����" << name << "\t��ţ�"
			     << individualEmpNo << endl <<"����"
			     << grade << endl << "���¹��ʣ�" << accumPay << "Ԫ"<<endl<<endl;
		}
};

class salesman :virtual public employee {
	protected:
		float CommRate;//��ɱ���
		float sales;//�������۶�
	public:
		salesman() {
			CommRate = 0.05;
		}
		void Pay() {
			cout << "�𾴵�" << name << ", " << individualEmpNo << "�Ź�Ա" << endl;
			cout << "�������۶� :" << endl;
			cin >> sales;
			accumPay = sales * CommRate;
			cout << "����Ա:" << name <<"\t��ţ�"
			     << individualEmpNo << endl
			     <<"���¹��ʣ�" << accumPay <<"Ԫ" << endl<< endl;
		}
		void displayStatus() {
			cout << "����Ա��" << name << "\t��ţ�"
			     << individualEmpNo << endl <<"����"
			     << grade << endl << "���¹��ʣ�" << accumPay << "Ԫ"<<endl<< endl;
		}
};

class salesmanager :public  manager ,public salesman {
	public:
		salesmanager() {
			monthlyPay = 6000;
			CommRate = 0.06;
		}
		void Pay() {
			cout << "�𾴵�" << name << ", " << salesman::individualEmpNo << "�Ź�Ա" << endl;
			cout << "�������۶� :" << endl;
			cin >> sales;
			salesman::accumPay = sales * CommRate + monthlyPay;
			cout << "���۾���:" << salesman::name <<"\t��ţ�"
			     << salesman::individualEmpNo << endl
			     <<"���¹��ʣ�" << salesman::accumPay <<"Ԫ" << endl<< endl;
		}
		void displayStatus() {
			cout << "���۾���" << salesman::name << "\t��ţ�"
			     << salesman::individualEmpNo << endl <<"����"
			     << salesman::grade << endl << "���¹��ʣ�" << salesman::accumPay << "Ԫ"<<endl<< endl;
		}
};

int main() {
	technician tech;
	manager mana;
	salesman sale;
	salesmanager salesm;
	tech.Pay();
	tech.displayStatus();
	mana.Pay();
	mana.displayStatus();
	sale.Pay();
	sale.displayStatus();
	salesm.Pay();
	salesm.displayStatus();
	return 0;
}
