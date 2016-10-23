//�ڴ���з���������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//��������
#define PROCESS_NAME_LEN 32    //����������󳤶� 
#define MIN_SLICE    10        //��С��Ƭ�Ĵ�С     
#define DEFAULT_MEM_SIZE 1024  //Ĭ�ϵ��ڴ�Ĵ�С   
#define DEFAULT_MEM_START 0    //Ĭ�ϵ��ڴ����ʼλ�� 

/*�ڴ�����㷨*/
#define MA_FF 1     //�״���Ӧ�㷨 
#define MA_BF 2		//�����Ӧ�㷨 
#define MA_WF 3		//���Ӧ�㷨 

int mem_size=DEFAULT_MEM_SIZE;   //�����ڴ��СΪĬ�ϵĴ�С
int ma_algorithm = MA_FF;        //��ʼ�������㷨Ϊ�״���Ӧ�㷨
static int pid = 0;              //��ʼ��pid
int flag = 0;                    //�����ڴ��С��־��Ϊ0��ʾδ���ã���Ĭ�ϴ�С
//����ÿһ�����п�����ݽṹ
struct free_block_type {
	int size;
	int start_addr;
	struct free_block_type *next;
};


struct free_block_type *free_block;//ָ���ڴ��п��п��������ָ�룬����������ͷ���

//ÿ�����̷��䵽���ڴ�������
struct allocated_block {
	int pid;         //����pid
	int size;		 //��С
	int start_addr;  //��ʼ��ַ
	char process_name[PROCESS_NAME_LEN]; //������
	struct allocated_block *next;		 //��һ�ڵ�
};

struct allocated_block *allocated_block_head = NULL;
//���̷�����ڴ���ͷ���

//��������
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
	free_block = init_free_block(mem_size); //��ʼ��������
	for(;;) {
		display_menu(); //��ʾ�˵�
		fflush(stdin);  //ˢ�¼��̻�����
		choice=getchar();   //��ȡ�û�����
		switch(choice) {
			case '1':
				set_mem_size();
				break;    //�����ڴ��С
			case '2':
				set_algorithm();
				flag=1;
				break;//�����㷨
			case '3':
				new_process();
				flag=1;
				break;//�����½���
			case '4':
				kill_process();
				flag=1;
				break;//ɾ������
			case '5':
				display_mem_usage();
				flag=1;
				break; //��ʾ�ڴ�ʹ��
			case '0':
				do_exit();
				exit(0);   //�ͷ������˳�
			default:
				break;
		}
	}
	return 1;
}

/*��ʼ�����п飬Ĭ��Ϊһ�飬����ָ����С����ʼ��ַ*/
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
	if(flag!=0) { //��ֹ�ظ�����
		printf("Cannot set memory size again\n");
		return 0;
	}
	printf("Total memory size =");
	scanf("%d", &size);
	if(size>0) {
		mem_size = size;
		free_block->size = mem_size;//���ÿ�������СΪ
	}
	flag=1;//��ֹ�ظ�����
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
		printf("��������,�ڴ��㷨ѡ��ΪĬ���㷨���״���Ӧ�㷨��\n");
	//��ָ���㷨�������п���������
	rearrange(ma_algorithm);//�����㷨ѡ���������� ������
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
*��FF�㷨���������ڴ���п�����
*Ҫ�󣺿��з��������յ�ַ�����Ĵ�������
***/

int rearrange_FF() {
	struct free_block_type *tmp, *work;
	printf("Rearrange free blocks for FF \n");
	tmp = free_block;
	while(tmp!=NULL) {
		work = tmp->next;
		while(work!=NULL) {
			if( work->start_addr < tmp->start_addr) { /*��ַ����*/
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
			if( work->size < tmp->size) { /*�������ռ��С��������*/
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
			if( work->size > tmp->size) { /*��������С�ݼ�����*/
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

/*�����µĽ��̣���Ҫ�ǻ�ȡ�ڴ����������*/
int new_process() {
	struct allocated_block *ab;
	int size;
	int ret;
	ab = (struct allocated_block *)malloc(sizeof(struct allocated_block));
	if(!ab) {
		exit(-5);//δ���뵽�ڵ㣬�൱��δ���뵽���̵�PCB
	}
	ab->next = NULL;
	pid++;//������̺�
	sprintf(ab->process_name, "PROCESS-%02d", pid);//������
	ab->pid = pid;//���̺�����
	while(1) {
		printf("Memory for %s:", ab->process_name);
		scanf("%d", &size);
		fflush(stdin);
		if(size>0) {
			ab->size=size;
			break;
		} else printf("�����С��������������\n");
	}
	ret = allocate_mem(ab);//�����ڴ�

	/*�����ʱallocated_block_head��δ��ֵ����ֵ*/
	if((ret==1) &&(allocated_block_head == NULL)) {
		allocated_block_head=ab;
		return 1;
	}
	/*����ɹ��������ѷ��������������ѷ�������*/
	else if (ret==1) {
		ab->next=allocated_block_head;
		allocated_block_head=ab;
		return 2;
	} else if(ret==-1) { /*���䲻�ɹ�*/
		printf("Allocation fail\n");
		free(ab);
		return -1;
	}

	return 3;
}

/*�����ڴ�ģ��*/

int allocate_mem(struct allocated_block *ab) {
	struct free_block_type *fbt, *pre;
	int request_size=ab->size;
	fbt = pre = free_block;
	while(fbt!=NULL) {
		int last = fbt->size - request_size;
		if(last > MIN_SLICE) { //�������㹻��/*�������пռ��㹻����ָ�*/
			ab->start_addr = fbt->start_addr;//�ڴ���׵�ַ
			fbt->start_addr += ab->size;//�޸���ʼ��ַ
			fbt->size -= ab->size;//�޸Ŀ������Ĵ�С
			return 1;
		} else if(last >= 0) { /*�ָ���������ΪС��Ƭ��һ�����*/
			ab->start_addr = fbt->start_addr;//�ڴ���׵�ַ
			ab->size = fbt->size;//�����ڴ��С
			if(fbt == free_block) {
				free_block = free_block->next;
				free(fbt);//�ͷ��׽ڵ�
				return 1;
			} else {
				pre->next = fbt->next;//�ͷŽڵ�
				free(fbt);
				return 1;
			}
		}
		/*
		if(fbt->size>=request_size) {
			//���в���********

		} else {

			//���в���******** }
			return 1;
		}*/
		pre = fbt;//��һ���ڵ�
		fbt = fbt->next;//���ڵĽڵ�
	}
	return -1;
}

/*ɾ�����̣��黹����Ĵ洢�ռ䣬��ɾ�������ý����ڴ����Ľڵ�*/

void kill_process() {
	struct allocated_block *ab;
	int pid;
	printf("Kill Process, pid=");
	scanf("%d", &pid);
	ab=find_process(pid);
	if(ab!=NULL) {
		free_mem(ab); /*�ͷ�ab����ʾ�ķ�����*/
		dispose(ab);  /*�ͷ�ab���ݽṹ�ڵ�*/
	} else {
		printf("δ�ҵ�ָ������\n");
	}
}

struct allocated_block *find_process(int pid) {
	struct allocated_block *ab=NULL;
	ab = allocated_block_head;
	while(NULL!=ab&&ab->pid!=pid)
		ab = ab->next;
	return ab;
}

/*��ab����ʾ���ѷ������黹�������п��ܵĺϲ�*/
// ���п��ܵĺϲ���������������
// 1. �����ͷŵĽ����뵽���з�������ĩβ
// 2. �Կ��������յ�ַ��������
// 3. ��鲢�ϲ����ڵĿ��з���
// 4. �������������°��յ�ǰ�㷨����
int free_mem(struct allocated_block *ab) {
	int algorithm = ma_algorithm;//���õ�ǰ�ڲ�ʹ���㷨 
	struct free_block_type *fbt, *pre, *work;

	fbt=(struct free_block_type*) malloc(sizeof(struct free_block_type));
	if(!fbt) return -1;
	fbt->size = ab->size;
	fbt->start_addr = ab->start_addr;
	/*���뵽�����������ͷ����������������ַ�����Ĵ�������*/
	fbt->next = free_block;
	free_block=fbt;
	rearrange(MA_FF);
	fbt=free_block;
	while(fbt!=NULL) {
		work = fbt->next;
		if(work!=NULL) {
			/*�����ǰ�����������Ŀ�������������ϲ�*/
			if(fbt->start_addr+fbt->size == work->start_addr) {
				fbt->size += work->size;
				fbt->next = work->next;
				free(work);
				continue;
			}
		}
		fbt = fbt->next;
	}
	rearrange(algorithm); /*���°���ǰ���㷨���п�����*/
	return 1;
}

/*�ͷ�ab���ݽṹ�ڵ�*/

int dispose(struct allocated_block *free_ab) {
	struct allocated_block *pre, *ab;
	if(free_ab == allocated_block_head) {/*���Ҫ�ͷŵ�һ���ڵ�*/
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

/* ��ʾ��ǰ�ڴ��ʹ�������������������������Ѿ��������� */

int display_mem_usage() {
	struct free_block_type *fbt=free_block;
	struct allocated_block *ab=allocated_block_head;
	//if(fbt==NULL) return(-1);//������Ϊ��ֱ���˳�������Ȼ��bug 
	printf("----------------------------------------------------------\n");

	/* ��ʾ������ */
	printf("Free Memory:\n");
	printf("%20s %20s\n", "      start_addr", "       size");
	while(fbt!=NULL) {
		printf("%20d %20d\n", fbt->start_addr, fbt->size);
		fbt=fbt->next;
	}
	/* ��ʾ�ѷ����� */
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
