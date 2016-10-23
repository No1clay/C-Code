#include<iostream>
using namespace std;
class fatherclass{
	int x;
	public:
		virtual void setData(int xx){
			x = xx;
		}
		void print(){
			cout << "The fatherclass's x is " << x << endl;
		}
}; 
class sonclass : public fatherclass{
	int x;
	public:
		void setData(int xx){
			x = xx+11;
		}
		void print(){
			cout << "The sonclass's x is " << x << endl;
		}
};
int main(){
	fatherclass father;
	sonclass son;
	fatherclass *fatherp=&father;
	fatherclass *sonp=&son;
	
	father.setData(11);
	father.print();
	son.setData(11);
	son.print();
	
	
	fatherp->setData(11);
	fatherp->print();
	sonp->setData(11);
	sonp->print();
	return 0;
}

