#include <stdio.h>
#include <stdlib.h>

//�����еĽṹ

typedef struct Link{
	
	  int elem; //����Ԫ��
	  struct Link *next; //ָ����һ���ڵ� 
}link;

//��ʼ��������

link *initLink();

// �����ӡ����

void display(link *p);

//������

int main(){
	
	//�����ʼ����1,2,3,4��
	printf("�����ʼ��\n"); 
	
	link *p = initLink();
	//��ӡ��������е�����
	display(p);
	
	return 0; 
	 
} 

//��ӵ�������

link *initLink(){
	
	link *p = NULL;//����ͷָ��
	link * temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
	
	//��ѡ�ڵ��ʼ��
	temp->elem = 1;
	temp->next = NULL;
	//�ڵ�pָ��ָ���ԭ�ڵ�
	p = temp;
	//������ڵ��������
	int i;
	for(i =2;i<5;i++){
		   
		    link *a=(link*)malloc(sizeof(link));
            a->elem=i;
            a->next=NULL;
            temp->next=a;
            temp=temp->next;

	} 
	
	return p;
	
} 

//��������

void display(link *p){
	  
	   //��ָ��ָ��ͷ�ڵ�
	   link *temp = p;
	   //ֻҪtemp ָ��ָ��Ĳ���NULL �ͼ�������ִ��
	   while(temp != NULL){
	   	   
	   	     printf("%d",temp->elem);
		     //ָ������
			 temp = temp->next;		 
	   } 
	   printf("\n"); 
} 






