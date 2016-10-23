#include<iostream>
#include<Cstring>
using namespace std;
class employee {
	protected:
		char *name;//姓名
		int individualEmpNo;//个人编号
		int grade;//级别
		float accumPay;//月薪总额
		static int employeeNo;//本公司职员数
	public:
		employee() {
			//构造函数
			individualEmpNo = employeeNo ++;//员工编号
			char name1[100];
			cout << "请输入"<< individualEmpNo << "号员工的名字：" << endl << endl;
			cin >> name1;
			name = new char [strlen(name1 ) + 1];
			strcpy(name , name1);
			grade = 1;//级别初值为1
			accumPay = 0.0; //月薪初始为0
		}
		~employee() { //析构函数
			delete [] name;
		}
		void pay() {

		}//计算月薪
		void promote(int inc) { //升级函数
			grade = grade + inc;
		}
		void displayStatus();//显示人员信息
};




int employee::employeeNo = 1;
class technician :public employee { //技术人员
	private:
		float hourlyRate;//每小时薪资
		int workHours;//当月工作数
	public:
		technician() {
			hourlyRate = 100;//每小时100元
		}
		void Pay() {
			cout << "尊敬的" << name << ", " << individualEmpNo << "号雇员" << endl; 
			cout << "本月工作时长 :" << endl;
			cin >> workHours;
			accumPay = workHours * hourlyRate;
			cout << "技术人员:" << name <<"\t编号："
			     << individualEmpNo << endl
			     <<"本月工资：" << accumPay <<"元" << endl << endl;
		}
		void displayStatus() {
			cout << "技术人员：" << name << "\t编号："
			     << individualEmpNo << endl <<"级别："
			     << grade << endl << "本月工资：" << accumPay <<endl<<endl;
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
			cout << "经理:" << name <<"\t编号："
			     << individualEmpNo << endl
			     <<"本月工资：" << accumPay <<"元" << endl<< endl;
		}
		void displayStatus() {
			cout << "经理：" << name << "\t编号："
			     << individualEmpNo << endl <<"级别："
			     << grade << endl << "本月工资：" << accumPay << "元"<<endl<<endl;
		}
};

class salesman :virtual public employee {
	protected:
		float CommRate;//提成比例
		float sales;//当月销售额
	public:
		salesman() {
			CommRate = 0.05;
		}
		void Pay() {
			cout << "尊敬的" << name << ", " << individualEmpNo << "号雇员" << endl;
			cout << "本月销售额 :" << endl;
			cin >> sales;
			accumPay = sales * CommRate;
			cout << "推销员:" << name <<"\t编号："
			     << individualEmpNo << endl
			     <<"本月工资：" << accumPay <<"元" << endl<< endl;
		}
		void displayStatus() {
			cout << "推销员：" << name << "\t编号："
			     << individualEmpNo << endl <<"级别："
			     << grade << endl << "本月工资：" << accumPay << "元"<<endl<< endl;
		}
};

class salesmanager :public  manager ,public salesman {
	public:
		salesmanager() {
			monthlyPay = 6000;
			CommRate = 0.06;
		}
		void Pay() {
			cout << "尊敬的" << name << ", " << salesman::individualEmpNo << "号雇员" << endl;
			cout << "本月销售额 :" << endl;
			cin >> sales;
			salesman::accumPay = sales * CommRate + monthlyPay;
			cout << "销售经理:" << salesman::name <<"\t编号："
			     << salesman::individualEmpNo << endl
			     <<"本月工资：" << salesman::accumPay <<"元" << endl<< endl;
		}
		void displayStatus() {
			cout << "销售经理：" << salesman::name << "\t编号："
			     << salesman::individualEmpNo << endl <<"级别："
			     << salesman::grade << endl << "本月工资：" << salesman::accumPay << "元"<<endl<< endl;
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
