#include<iostream>
using namespace std;
class node { //节点类
	public:
		node(int d ,node *n=0) {
			data=d;
			next=n;
		}
		friend class list;//链表list是节点类node的友元类
	private:
		int data;
		node *next;
};
class list {
	public:
		list() {
			head=tail=0;
			node_count=0;
		}
		~list() {
			while(head) {
				node *temp=head;
				head=head->next;
				delete temp;
			}
		}
		void addend(int i) {
			if(node_count==0) {
				node *n=new node(i);
				head=tail=n;
			} else {
				node *n=new node(i);
				tail->next=n;
				tail=n;
			}
			node_count++;
			tail->next=0;
		}
		void show(){
			node *p=head;
			while(p){
				cout<<p->data<<endl;
				p=p->next;
			}
		}
		private:
			node *head,*tail;
			int node_count;
};
int main(){
	list Lst;
	for(int i;i<6;i++){
		Lst.addend(i+66);
	}
	Lst.show();
	return 0;
}
