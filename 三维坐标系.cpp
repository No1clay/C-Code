#include<iostream>
using namespace std;
class three_d{
	int x , y, z;
	public:
		three_d(int i , int j ,int k){
			x = i;
			y = j;
			z = k;
		}
		three_d(){
			x = 0;
			y = 0;
			z = 0;
		} 
		void get(int &i ,int &j ,int &k){
			i = x;
			j = y;
			k = z;
		}
		three_d operator +(const three_d &other){
			int i = x + other.x;
			int j = y + other.y;
			int k = z + other.z;
			return three_d(i , j , k); 
		}
		three_d &operator = (const three_d &s){
			if(this == &s){
				return *this;
			}
			x = s.x;
			y = s.y;
			z = s.z;
			return *this;
		}
		three_d operator ++(){
			++x;
			++y;
			++z;
			return *this;
		} 
		three_d operator --(){
			--x;
			--y;
			--z;
			return *this;
		}
		void print(){
			cout << "x = " << x;
			cout << "\ty = " << y;
			cout << "\tz = " << z << endl;
		}
};
int main(){
	three_d t1(1,2,3),t2(1,2,3),t3,t4;
	t1.print();
	t2.print();
	t3 = t1 + t2;
	t4 = t2;
	t3.print();
	t4.print();
	++t3;
	t3.print();
	--t3;
	t3.print();

	return 0;
}

