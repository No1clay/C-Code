#include<iostream>
using namespace std;
int main() {
	int side;
	cin >> side;

	int x[4] = {1,0,-1,0};
	int	y[4] = {0,1,0,-1};

	int martix[100][100];
	int count = 1;
	int r = 1, type =0;
	int mi,mj;
	mi = mj = (side -1) /2;
	martix [ mi][mj ]= count++;
	while(count <= side *side) {
		for(int i=1 ; i <= (r + 1)/2; i++) {
			mi = mi + x[type];
			mj = mj + y[type];
			martix[mi][mj] = count++;
		}
		r++;
		type= (type+1)%4;
	}
	for(int a = 0; a< side; a ++) {
		for(int b = 0; b < side; b ++) {
			printf("%3d ",martix[a][b]);
		}
		cout << endl;
	}
	printf("%d",count);
	return 0;
}

