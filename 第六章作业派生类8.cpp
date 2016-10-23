#include<iostream>
using namespace std;
class planet{
	protected:
		double distance;
		int revolve;
	public:
		planet(double d, int r){
			distance = d;
			revolve = r;
		}
};
class earth : public planet{
	double circumference;
	public:
		/*Create earth(double d, int r).
		Have it pass the distance and days of
		revolution back to planet. 
		Have it compute the  circumference of the orbit.
		(Hint :circumference = 2 * r * 3.1416 */
		earth(double d , int r):planet(d, r){
			
			circumference = 2 * r * 3.1416;
		} 
		/*Create a function called show() that displays
		the information.*/
		void show(){
			cout << "The distance between earth and sun is " << distance << endl;
			cout << "The revolve is " << revolve << endl;
			cout << "The circumference is " << circumference << endl; 

		}
};
int main(){
	earth ob(93000000, 365);
	ob.show();
	return 0;
}

