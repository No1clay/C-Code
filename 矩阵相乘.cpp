# include <stdio.h>
#include<malloc.h>
void arrmy( int **a,int **b,int **c,int m,int n,int s) {
	int temp;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) {
			temp=0;
			for(int k=0; k<s; k++) {
				temp+=a[i][k]*b[k][j];
			}
			c[i][j]=temp;
			printf("%5d",c[i][j]);
			printf("\n");
		}
}
int main () {
	int **a,**b,**c; 
	int m,s,n;
	int i,j;
	printf("������Ҫ����ĵ�һ����������������");
	scanf("%d%d",&m,&s);
	printf("���������İ�����");
	a=(int**)malloc(m*sizeof(int *));
	for(i=0;i<m;i++){
		printf("�������%d�����ݣ�",i+1);
		a[i]=(int *)malloc(s*sizeof(int));
		for(j=0;j<s;j++){
			fflush(stdin);
			scanf("%d",&a[i][j]);
		}
	}
	printf("������Ҫ����ĵڶ������������");
	scanf("%d",&n);
	printf("��������������");
	b=(int**)malloc(s*sizeof(int *));
	for(i=0;i<s;i++){
		printf("�������%d�����ݣ�",i+1);
		b[i]=(int *)malloc(n*sizeof(int));
		for(j=0;j<n;j++){
			fflush(stdin);
			scanf("%d",&b[i][j]);
		}
	}
	c=(int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++){
		c[i]=(int *)malloc(n*sizeof(int));
		for(j=0;j<n;j++){
			c[i][j]=0;
		}
	}
	arrmy(a,b,c,m,n,s);
}
		
