//内存空闲分区的描述
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//常量定义
#define PROCESS_NAME_LEN 32    //进程名称最大长度 
#define MIN_SLICE    10        //最小碎片的大小     
#define DEFAULT_MEM_SIZE 1024  //默认的内存的大小   
#define DEFAULT_MEM_START 0    //默认的内存的起始位置 

/*内存分配算法*/
#define MA_FF 1     //首次适应算法 
#define MA_BF 2		//最佳适应算法 
#define MA_WF 3		//最坏适应算法 

int mem_size=DEFAULT_MEM_SIZE;   //设置内存大小为默认的大小
int ma_algorithm = MA_FF;        //初始化分配算法为首次适应算法
static int pid = 0;              //初始化pid
int flag = 0;                    //设置内存大小标志，为0表示未设置，即默认大小
//描述每一个空闲块的数据结构
struct free_block_type {
	int size;
	int start_addr;
	struct free_block_type *next;
};


struct free_block_type *free_block;//指向内存中空闲块链表的首指针，即空闲链的头结点

//每个进程分配到的内存快的描述
struct allocated_block {
	int pid;         //进程pid
	int size;		 //大小
	int start_addr;  //起始地址
	char process_name[PROCESS_NAME_LEN]; //进程名
	struct allocated_block *next;		 //下一节点
};

struct allocated_block *allocated_block_head = NULL;
//进程分配的内存块的头结点

//函数声明
struct free_block_type* init_free_block(int mem_size);
void display_menu();
int set_mem_size();
void set_algorithm();
void rearrange(int algorithm);
int rearrange_FF();
int rearrange_BF();
int rearrange_WF();
int new_process();
int allocate_mem(struct allocated_block *ab);
void kill_process();
int free_mem(struct allocated_block *ab);
int dispose(struct allocated_block *free_ab);
int display_mem_usage();
void do_exit();
struct allocated_block *find_process(int pid);


int main() {
	char choice;
	pid=0;
	free_block = init_free_block(mem_size); //初始化空闲区
	for(;;) {
		display_menu(); //显示菜单
		fflush(stdin);  //刷新键盘缓冲区
		choice=getchar();   //获取用户输入
		switch(choice) {
			case '1':
				set_mem_size();
				break;    //设置内存大小
			case '2':
				set_algorithm();
				flag=1;
				break;//设置算法
			case '3':
				new_process();
				flag=1;
				break;//创建新进程
			case '4':
				kill_process();
				flag=1;
				break;//删除进程
			case '5':
				display_mem_usage();
				flag=1;
				break; //显示内存使用
			case '0':
				do_exit();
				exit(0);   //释放链表并退出
			default:
				break;
		}
	}
	return 1;
}

/*初始化空闲块，默认为一块，可以指定大小及起始地址*/
struct free_block_type* init_free_block(int mem_size) {
	struct free_block_type *fb;

	fb=(struct free_block_type *)malloc(sizeof(struct free_block_type));
	if(fb==NULL) {
		printf("No mem\n");
		return NULL;
	}
	fb->size = mem_size;
	fb->start_addr = DEFAULT_MEM_START;
	fb->next = NULL;
	return fb;
}


void display_menu() {
	printf("\n");
	printf("1 - Set memory size (default=%d)\n", DEFAULT_MEM_SIZE);
	printf("2 - Select memory allocation algorithm\n");
	printf("3 - New process \n");
	printf("4 - Terminate a process \n");
	printf("5 - Display memory usage \n");
	printf("0 - Exit\n");
}


int set_mem_size() {
	int size;
	if(flag!=0) { //防止重复设置
		printf("Cannot set memory size again\n");
		return 0;
	}
	printf("Total memory size =");
	scanf("%d", &size);
	if(size>0) {
		mem_size = size;
		free_block->size = mem_size;//设置空闲区大小为
	}
	flag=1;//防止重复设置
	return 1;
}

void set_algorithm() {
	int algorithm;
	printf("\t1 - First Fit\n");
	printf("\t2 - Best Fit \n");
	printf("\t3 - Worst Fit \n");
	scanf("%d", &algorithm);
	if(algorithm>=1 && algorithm <=3)  {
		ma_algorithm = algorithm;
	} else
		printf("输入有误,内存算法选择为默认算法：首次适应算法！\n");
	//按指定算法重新排列空闲区链表
	rearrange(ma_algorithm);//分配算法选择，重新排列 空闲区
}


void rearrange(int algorithm) {
	switch(algorithm) {
		case MA_FF:
			rearrange_FF();
			break;
		case MA_BF:
			rearrange_BF();
			break;
		case MA_WF:
			rearrange_WF();
			break;
	}
}
void swap(int *last,int *dest) {
	int t;
	t = *dest;
	*dest = *last;
	*last = t;
}
/***
*按FF算法重新整理内存空闲块链表
*要求：空闲分区链按照地址递增的次序链接
***/

int rearrange_FF() {
	struct free_block_type *tmp, *work;
	printf("Rearrange free blocks for FF \n");
	tmp = free_block;
	while(tmp!=NULL) {
		work = tmp->next;
		while(work!=NULL) {
			if( work->start_addr < tmp->start_addr) { /*地址递增*/
				swap(&work->start_addr, &tmp->start_addr);
				swap(&work->size, &tmp->size);
			} else {
				work=work->next;
			}
		}
		tmp=tmp->next;
	}
	return 0;
}

int rearrange_BF() {
	struct free_block_type *tmp, *work;
	printf("Rearrange free blocks for FF \n");
	tmp = free_block;
	while(tmp!=NULL) {
		work = tmp->next;
		while(work!=NULL) {
			if( work->size < tmp->size) { /*空闲区空间大小递增排序*/
				swap(&work->start_addr, &tmp->start_addr);
				swap(&work->size, &tmp->size);
			} else {
				work=work->next;
			}
		}
		tmp=tmp->next;
	}
	return 0;
}

int rearrange_WF() {
	struct free_block_type *tmp, *work;
	printf("Rearrange free blocks for FF \n");
	tmp = free_block;
	while(tmp!=NULL) {
		work = tmp->next;
		while(work!=NULL) {
			if( work->size > tmp->size) { /*空闲区大小递减排序*/
				swap(&work->start_addr, &tmp->start_addr);
				swap(&work->size, &tmp->size);
			} else {
				work=work->next;
			}
		}
		tmp=tmp->next;
	}
	return 0;
}

/*创建新的进程，主要是获取内存的申请数量*/
int new_process() {
	struct allocated_block *ab;
	int size;
	int ret;
	ab = (struct allocated_block *)malloc(sizeof(struct allocated_block));
	if(!ab) {
		exit(-5);//未申请到节点，相当于未申请到进程的PCB
	}
	ab->next = NULL;
	pid++;//申请进程号
	sprintf(ab->process_name, "PROCESS-%02d", pid);//进程名
	ab->pid = pid;//进程号设置
	while(1) {
		printf("Memory for %s:", ab->process_name);
		scanf("%d", &size);
		fflush(stdin);
		if(size>0) {
			ab->size=size;
			break;
		} else printf("输入大小有误，请重新输入\n");
	}
	ret = allocate_mem(ab);//分配内存

	/*如果此时allocated_block_head尚未赋值，则赋值*/
	if((ret==1) &&(allocated_block_head == NULL)) {
		allocated_block_head=ab;
		return 1;
	}
	/*分配成功，将该已分配块的描述插入已分配链表*/
	else if (ret==1) {
		ab->next=allocated_block_head;
		allocated_block_head=ab;
		return 2;
	} else if(ret==-1) { /*分配不成功*/
		printf("Allocation fail\n");
		free(ab);
		return -1;
	}

	return 3;
}

/*分配内存模块*/

int allocate_mem(struct allocated_block *ab) {
	struct free_block_type *fbt, *pre;
	int request_size=ab->size;
	fbt = pre = free_block;
	while(fbt!=NULL) {
		int last = fbt->size - request_size;
		if(last > MIN_SLICE) { //空闲区足够大/*分配后空闲空间足够大，则分割*/
			ab->start_addr = fbt->start_addr;//内存块首地址
			fbt->start_addr += ab->size;//修改起始地址
			fbt->size -= ab->size;//修改空闲区的大小
			return 1;
		} else if(last >= 0) { /*分割后空闲区成为小碎片，一起分配*/
			ab->start_addr = fbt->start_addr;//内存块首地址
			ab->size = fbt->size;//分配内存大小
			if(fbt == free_block) {
				free_block = free_block->next;
				free(fbt);//释放首节点
				return 1;
			} else {
				pre->next = fbt->next;//释放节点
				free(fbt);
				return 1;
			}
		}
		/*
		if(fbt->size>=request_size) {
			//自行补充********

		} else {

			//自行补充******** }
			return 1;
		}*/
		pre = fbt;//上一个节点
		fbt = fbt->next;//现在的节点
	}
	return -1;
}

/*删除进程，归还分配的存储空间，并删除描述该进程内存分配的节点*/

void kill_process() {
	struct allocated_block *ab;
	int pid;
	printf("Kill Process, pid=");
	scanf("%d", &pid);
	ab=find_process(pid);
	if(ab!=NULL) {
		free_mem(ab); /*释放ab所表示的分配区*/
		dispose(ab);  /*释放ab数据结构节点*/
	} else {
		printf("未找到指定进程\n");
	}
}

struct allocated_block *find_process(int pid) {
	struct allocated_block *ab=NULL;
	ab = allocated_block_head;
	while(NULL!=ab&&ab->pid!=pid)
		ab = ab->next;
	return ab;
}

/*将ab所表示的已分配区归还，并进行可能的合并*/
// 进行可能的合并，基本策略如下
// 1. 将新释放的结点插入到空闲分区队列末尾
// 2. 对空闲链表按照地址有序排列
// 3. 检查并合并相邻的空闲分区
// 4. 将空闲链表重新按照当前算法排序
int free_mem(struct allocated_block *ab) {
	int algorithm = ma_algorithm;//设置当前内部使用算法 
	struct free_block_type *fbt, *pre, *work;

	fbt=(struct free_block_type*) malloc(sizeof(struct free_block_type));
	if(!fbt) return -1;
	fbt->size = ab->size;
	fbt->start_addr = ab->start_addr;
	/*插入到空闲区链表的头部并将空闲区按地址递增的次序排列*/
	fbt->next = free_block;
	free_block=fbt;
	rearrange(MA_FF);
	fbt=free_block;
	while(fbt!=NULL) {
		work = fbt->next;
		if(work!=NULL) {
			/*如果当前空闲区与后面的空闲区相连，则合并*/
			if(fbt->start_addr+fbt->size == work->start_addr) {
				fbt->size += work->size;
				fbt->next = work->next;
				free(work);
				continue;
			}
		}
		fbt = fbt->next;
	}
	rearrange(algorithm); /*重新按当前的算法排列空闲区*/
	return 1;
}

/*释放ab数据结构节点*/

int dispose(struct allocated_block *free_ab) {
	struct allocated_block *pre, *ab;
	if(free_ab == allocated_block_head) {/*如果要释放第一个节点*/
		allocated_block_head = allocated_block_head->next;
		free(free_ab);
		return 1;
	}
	pre = allocated_block_head;
	ab = allocated_block_head->next;
	while(ab!=free_ab) {
		pre = ab;
		ab = ab->next;
	}
	pre->next = ab->next;
	free(ab);
	return 2;
}

/* 显示当前内存的使用情况，包括空闲区的情况和已经分配的情况 */

int display_mem_usage() {
	struct free_block_type *fbt=free_block;
	struct allocated_block *ab=allocated_block_head;
	//if(fbt==NULL) return(-1);//空闲区为空直接退出，很显然是bug 
	printf("----------------------------------------------------------\n");

	/* 显示空闲区 */
	printf("Free Memory:\n");
	printf("%20s %20s\n", "      start_addr", "       size");
	while(fbt!=NULL) {
		printf("%20d %20d\n", fbt->start_addr, fbt->size);
		fbt=fbt->next;
	}
	/* 显示已分配区 */
	printf("\nUsed Memory:\n");
	printf("%10s %20s %10s %10s\n", "PID", "ProcessName", "start_addr", " size");
	while(ab!=NULL) {
		printf("%10d %20s %10d %10d\n", ab->pid, ab->process_name, ab->start_addr, ab->size);
		ab=ab->next;
	}
	printf("----------------------------------------------------------\n");
	return 0;
}

void do_exit() {

}
