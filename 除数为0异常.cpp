#include<iostream>
using namespace std;
int main() {
	int m, n;
	cout << "Please input two integers: ";
	cin >> m >> n;
	try {
		if (n == 0) {
			throw 0;
		}
		cout <<(m / n) << endl;
	} catch(int) {
		cout << "Divied by 0!" << endl;
		return -1;
	}
	return 0;
}
