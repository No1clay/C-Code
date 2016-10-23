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
	printf("请输入要计算的第一个矩阵行数和列数");
	scanf("%d%d",&m,&s);
	printf("请输入矩阵的包含数");
	a=(int**)malloc(m*sizeof(int *));
	for(i=0;i<m;i++){
		printf("请输入第%d行数据：",i+1);
		a[i]=(int *)malloc(s*sizeof(int));
		for(j=0;j<s;j++){
			fflush(stdin);
			scanf("%d",&a[i][j]);
		}
	}
	printf("请输入要计算的第二个矩阵的列数");
	scanf("%d",&n);
	printf("请输入矩阵包含数");
	b=(int**)malloc(s*sizeof(int *));
	for(i=0;i<s;i++){
		printf("请输入第%d行数据：",i+1);
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
		
