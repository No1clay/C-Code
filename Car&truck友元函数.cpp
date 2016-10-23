#include<iostream>
using namespace std;
class truck;
class car{
	int passengers;
	int speed;
	public:
		car(int p,int s){
			passengers =p;
			speed=s;
		}
		friend int sp_greater(car c,truck t);
}; 
class truck{
	int weight;
	int speed;
	public:
		truck(int w,int s){
			weight=w;
			speed=s;
		}
		friend int sp_greater(car c,truck t);
};
int sp_greater(car c,truck t){
	return c.speed-t.speed;
}
int main()
{
	car c(5,6);
	truck t(5,6);
	cout<<"The sp_greater of c and t is "<<sp_greater(c,t);
	return 0;
}
