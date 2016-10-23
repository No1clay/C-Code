#include<iostream>
using namespace std;
template <class T>
void sort(T a[], int n ) {
	int i , j, k;
	T temp;
	for(i=0; i< n - 1; i++) {
		k=i;
		for(j=i+1; j< n; j++) {
			if(a[j]<a[k]) {
				k=j;
			}
		}
		if(i!=k) {
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
}
int main() {
	/*int arr[7] = {1 , 7 , -5 , 3 , 6 ,1 ,2};
	double arr2[7] = {2.3 , 7.8 , 1.2 ,6.3 ,4.5 ,7.6 ,3.2};
	sort(arr , 7);
	for (int i = 0 ;i < 7 ;i ++){
		cout << arr[i] << " " ;
	}
	cout << endl;
	sort(arr2 , 7);
	for (int i = 0 ;i < 7 ;i ++){
		cout << arr2[i] << " " ;
	}*/
	int num, num1;
	cin >> num;
	int *arr = new int[num];
	for(int i = 0; i < num ; i++) {
		cin >> arr[i];
	}
	sort(arr , num);
	cin >> num1;
	double *arr2 = new double[num1];
	for(int i = 0; i < num1 ; i++) {
		cin >> arr2[i];
	}
	sort(arr2 , num1);
	for(int i = 0; i < num; i ++) {
		cout << arr[i] << " " ;
	}
	cout << endl;
	for(int i = 0; i < num1; i ++) {
		cout << arr2[i] << " " ;
	}
	return 0;
}

