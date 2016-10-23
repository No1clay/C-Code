#include<iostream>
#include<string.h>
using namespace std;
class Stock {
	char symbol[20];
	char name[20];
	double previousClosingPrice;
	double currentPrice;
	public:
		Stock(char *STOCK_SYMBOL,char *STOCK_NAME,double STOCK_previousClosingPrice,double STOCK_currentPrice);
		char * getChangePercent(){
			double ans=(currentPrice-previousClosingPrice)/previousClosingPrice;
			char ansname[20];
			sprintf(ansname,"%.2lf%%",ans*100);
			return ansname;
		}
};
Stock::Stock(char *STOCK_SYMBOL,char *STOCK_NAME,double STOCK_previousClosingPrice,double STOCK_currentPrice){
	strcpy(symbol,STOCK_SYMBOL);
	strcpy(name,STOCK_NAME);
	previousClosingPrice=STOCK_previousClosingPrice;
	currentPrice=STOCK_currentPrice;
}
int main(){
	char symbol[20];
	char name[20];
	double preprice;
	double cprice;
	cin>>symbol>>name>>preprice>>cprice;
	Stock st1(symbol,name,preprice,cprice);
	cout<<st1.getChangePercent();
	return 0;
}
