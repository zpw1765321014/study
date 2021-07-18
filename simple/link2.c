#include <stdio.h>
#include <stdlib.h>

//��������ṹ��
typedef struct Link 
{
	
	 int elem;            //����������� 
	 struct Link *next;   //�����ָ���� 
} link;
//��ʼ������
link *initLink();

//����չʾ����
void dispay();

// ���������е�Ԫ��
void find(link *p);

//�޸�ĳ���ڵ������
link *edit(link *p,int old,int new);

//�޸�ĳ���ڵ������
link *del(link *p,int elem);

//������ 
int main()
{
	
	//�����ʼ��
	printf("���������ʼ��\n");
	//�����ʼ�� 
	link *p = initLink();
	display(p);
    //���Ҷ�Ӧ������
	//find(p);
	link *p1 = edit(p,10,50);
	// ��ӡչ���������� 
    display(p1);
    
    //link *p2 = del(p,3);
	// ��ӡչ���������� 
    //display(p2);
	return 0;
}
//ɾ����ǰԪ�صĽڵ� 
link *del(link *p,int elem)
{
	int flag = 0;
	//��temp ָ������ָ��ͷ���
	  link *temp = p;
	  //ֻ��temp  ������ NULL��ʱ��ڵ����ݼ��������� 
	  while(temp->next != NULL)
	  {
	  	    temp = temp->next;   //ָ����һ���ڵ� 
	  	    if(temp->elem == elem)
		    {
		   	   printf("�ҵ��˸�����ɾ���ɹ���");
		   	   temp = temp->next->next; 
		   	   flag =1;
			   break; 
		    }
	  } 
	  if(flag == 0)
	  {
	  	  printf("û���ҵ���Ҫɾ��������Ŷ!");
	  	  return NULL;
	  }
	  return p;
} 
//�޸ĵ�ǰԪ�صĽڵ� 
link *edit(link *p,int old,int new)
{    
      int flag = 0;
	//��temp ָ������ָ��ͷ���
	  link *temp = p;
	  //ֻ��temp  ������ NULL��ʱ��ڵ����ݼ��������� 
	  while(temp->next != NULL)
	  {
	  	    temp = temp->next;   //ָ����һ���ڵ� 
	  	    if(temp->elem == old)
		    {
		   	   printf("�ҵ��˸�����,�滻�ɹ���");
		   	   temp->elem = new; 
		   	   flag =1;
			   break; 
		    }
	  } 
	  if(flag == 0)
	  {
	  	  printf("û���ҵ���Ҫ�滻������Ŷ!");
	  	  return NULL;
	  }
	  return p;
}
//���Ҷ�Ӧ��Ԫ�� 
void find(link *p)
{     
      int elem;
      scanf("%d",&elem);
      int flag = 0;
	 //��temp ָ������ָ��ͷ���
	  link *temp = p;
	  while(temp->next != NULL)
	  {
	  	   temp = temp->next;   //ָ����һ���ڵ� 
	  	   if(temp->elem == elem)
		   {
		   	   printf("�ҵ��˸�����");
		   	   printf("%d",temp->elem);
		   	   flag =1;
			   break; 
		   }
		  
	  }
	  //��ʾû�ҵ���Ӧ������ 
	  if(flag == 0)
	  {
	  	   printf("û�ҵ��˸�����");
	  }
	 	  
}
//����չʾ 
void display(link *p)
{
	 
	  //��temp ָ������ָ��ͷ���
	  link *temp = p;
	  //ֻ��temp  ������ NULL��ʱ��ڵ����ݼ��������� 
	  while(temp->next != NULL)
	  {
	  	    temp = temp->next;   //ָ����һ���ڵ� 
	  	    printf("----"); 
	  	    printf("%d",temp->elem); 
	  	    printf("\n");
	  } 
	   
} 
//�������ݳ�ʼ��
link *initLink()
{
	
	 link *p = (link*)malloc(sizeof(link)); //����һ��ͷ��� ����һ��ָ��ռ� 
	 link *temp = p; //����һ��ָ��ָ����ڵ�,���ڱ�������
	 //��������
	 int i;
	 for(i=0; i<5; i++){
	 	  
	 	   link *a = (link*)malloc(sizeof(link));
	 	   a->elem = i;
	 	   a->next = NULL;
	 	   temp->next = a;
	 	   //temp = temp->next;
	 	   temp = a;//�޸�ͷ����ָ�� 
	 }
	 return p; 
} 

