#include<stdio.h>
#include <stdlib.h>

typedef struct node 
{   

	int number;
	struct node *next; //node �Ľṹ��ָ�� ָ����һ���ڵ�ĵ�ַ 
	
}person;

//�����ʼ��
person *initLink(int n)
{    
    int i; 
	person *head = (person*)malloc(sizeof(person)); //ͷ��㲢����ָ��ռ�
	head->number = 1;
	head->next   = NULL;
	//���������ڵ�
	person *cycle = head;
	//����ѭ������ 
    for(i=2;i<=n;i++)
	{
	 	person *body = (person*)malloc(sizeof(person));
	 	body->number = i;
	 	body->next   = NULL;  //ָ��ڵ�ָ��� 
	 	cycle->next  = body; //ָ���½ڵ�
		cycle        = body;  //�����ڵ���� 
	} 
	//β���ڵ�ָ��ͷ���
	cycle->next = head;
	return head; 
} 
//���Ҷ�Ӧ���� 
void findAndKillK(person * head,int k,int m)
{
	person *tail = head;
	
	//�ҵ�����ĵ�һ���ڵ� Ϊ����ɾ����׼��
	while(tail->next != head){
		 
		 printf("%d\n",tail->number); 
		 tail = tail->next;  //Ԫ�صĵ�һ���ڵ� 
		
	} 
	//printf("Ԫ�صĵ�һ��ֵ�Ƕ���:"); 
	//��ӡ�鿴Ԫ�� 
	//printf("%d",tail->number); 
	person *p =head;
	//�ҵ����Ϊk����
	while(p->number != k)
	{
		tail = p;
		p = p->next;
	} 
	//�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ�������
	while (p->next!=p) 
	{   
	     int i;
		//�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
        for (i=1; i<m; i++) {
            tail=p;
            p=p->next;
        }
        
        tail->next=p->next;//�������Ͻ�p���ժ����
        printf("�����˵ı��Ϊ:%d\n",p->number);
        
        free(p);
        p=tail->next;//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
	}
	printf("�����˵ı��Ϊ:%d\n",p->number);
    free(p);
}
//������ 
int main()
{   
    printf("����Բ���ϵ�����n:");
    int n;
    scanf("%d",&n);
    person * head=initLink(n);
    printf("�ӵ�k�˿�ʼ����(k>1��k<%d)��",n);
    int k;
    scanf("%d",&k);
    printf("����m���˳��У�");
    int m;
    scanf("%d",&m);
    findAndKillK(head, k, m);
    
    return 0;
	
}
