#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student
{
   	  char name[20];    //����
      char num[15];      //ѧ��
    
      struct student *next;  //�ṹ��ָ�� ָ����һ���ڵ�Ĵ�����ݵ� 
}stu;
//�ṹ��ͷָ�� 
stu *head;
//��Ļ��ʾ 
void screen();
//���˵�
void print(); 
//�û��������
void input(stu *p1);
//��������ĺ���
stu * inputdata();
//��ʾ���� 
stu * lookdata(stu *p1);
//��������
void insert();    
//ɾ����Ӧ������ 
void deleted();    
//���Ҷ�Ӧ������
void find(stu *p2);  
 //ͨ�����������޸�����    
void update(stu *p2); 

//����������Ϣ
void save(stu *p2); 

//������ 
int main()
{
	int i;
    system("color 4e");
	screen();
	//��ʱ30�� 
	Sleep(3000);
	//��ʾ���˵� 
	print();
	//��ȡ�û��������Ϣ
	while(1)
	{
		printf("���������ѡ��(1~9):");
        loop:scanf("%d",&i);
         if(i<1||i>9)
         {
             printf("��������,����1~9�н���ѡ��:");
             goto loop;
         }
         //���Ҷ�Ӧ�Ĺ��� 
         switch(i)
		 {
		 	case 1:
		 		inputdata();
		 		break;
		 	case 2:
		 		lookdata(head);
		 		break;
		 	case 3:
			   insert();
			   break;	
			case 4:
			   deleted();
			   break;
			case 5:
			   find(head);
			   break;
			case 6:
			   update(head);
			   break;
			case 7:
			   save(head);
			   break;
			case 8:
			   print();
			   break;
		    case 9:
		    	printf("�˳���¼\n");
			    exit(1);
				break;		  
		 }
	} 
}
//�������� 
void save(stu *p2)
{
	FILE *fp;
	char file[15]; //�ļ�����
	printf("\n\t\t\t��������ݡ���\n"); 
	printf("----------------------------------------------------------------------\n");
	printf("�����ļ���:");
	scanf("%s",&file);
	//��д�ķ�ʽ���ļ� 
	if((fp=fopen(file,"w"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	} 
	fprintf(fp,"����\tѧ��\n");
	//��ȡ�����ļ�
	while(p2 != NULL)
	{
		 fprintf(fp,"%s\t",p2->name);
         fprintf(fp,"%s\t",p2->num);
         //ָ�����
		 p2 = p2->next; 
	} 
	
	printf("\n����ɹ�!\n");
	printf("======================================================================\n");
	fclose(fp); //�ر��ļ� 
}
//���¶�Ӧ������ 
void update(stu *p2)
{
	
	 char name [20];
	 int b=0,i;
	 printf("\n\t\t\t�����޸����ݡ���\n");
	 printf("----------------------------------------------------------------------\n");
	 printf("�����뽫Ҫ�޸��˵�����:");
	 scanf("%s",name);
	 //1.�п����ǿ����������Ҫ������
	 if(p2 == NULL)
	 {
	 	
	 	 printf("ͨѶ¼����Ϊ��Ŷ\n");
	 	 return ;
	 } 
	 //�����������ݵ�ʱ��
	 while(p2 != NULL)
	 { 
	       
		   //�������������
		   if(strcmp(name,p2->name) == 0)
		   {      
		         /****************���뵱ǰѧ���Ļ�����Ϣ start**********************/
		   	     printf("��ͬѧ�Ļ�����Ϣ\n");
		   	     printf("����:%s\n",p2->name);
		   	     printf("ѧ��:%s\t",p2->num);
		   	     /****************���뵱ǰѧ���Ļ�����Ϣ end**********************/
		   	     printf("\n��ѡ��Ҫ�޸ĵ���Ϣ\n");
		   	     printf("\t1.����\t2.ѧ��\n");
		   	     printf("\n����ѡ����(1~8):");
		   	     scanf("%d",&i);
		   	     printf("�������޸�֮�������\n");
		   	     //���߱�ʶ�޸Ķ�Ӧ������ 
		   	     switch(i)
				 {
				 	 case 1:
					   printf("����������:");
					   scanf("%s",&p2->name);
					   break;
					 case 2:
					    printf("������ѧ��:");
						scanf("%s",&p2->num);
						break;
					  
				 }
				 //��ʾ�޸ĳɹ���
				 printf("\n�޸ĳɹ�!\n");
				 printf("----------------------------------------------------------------------\n");
				 b = 1; //�����޸ı�ʶ 
		   }	
		   
		   //ָ��ڵ������ƶ�
		   p2 = p2->next;
		   
		  
	 } 
	  //�жϸ�ѧ������Ϣ�Ƿ����
		if(b == 0)
		{  
		   	  printf("û���ҵ����˵�����\n");
		} 
		return ;
}
//���Ҷ�Ӧ�ĺ��� 
void find(stu *p2)
{
	 char name[20];
	 int b = 0;
	 printf("\n\t\t\t����鿴���ݡ���\n");
	 printf("----------------------------------------------------------------------\n");
	 printf("��������������˵�����:");
	 //��ȡ�����˵�����
	 scanf("%s",name);
	 //1.�п����ǿ����������Ҫ������
	 if(p2 == NULL){
	 	
	 	 printf("ͨѶ¼����Ϊ��Ŷ\n");
	 	 return ;
	 } 
	 //����������Ҷ�Ӧ������
	 while(p2!=NULL)
	 {     
	       //�ҵ���Ӧ����Ա����Ӧ����ʾ���� 
	 	  if(strcmp(name,p2->name) == 0)
		   {
		   	   printf("��Ҫ�ҵ�������\n");
               printf("����:%s\n",p2->name);
               printf("ѧ��:%s\t",p2->num);
               printf("\n");
               //��ʶ�ҵ���Ӧ�������� 
               b = 1; 
		   }
		   //ָ��ڵ������ƶ�
		   p2 = p2->next; 
	 } 
	 //�ж������Ƿ���� 
	 if(b == 0)
	 { 
	     printf("\n��Ҫ���ҵ��˲�����!\n");
		 return ;	
	 }
}
//ɾ������ 
void deleted() 
{
    stu *p1,*p2; //���������ṹ��ָ��
    char Name[20]; //��Ҫɾ���û�������
	printf("\n\t\t\t����ɾ�����ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    printf("������Ҫɾ��������:");   
    //��ȡ�û����������
	scanf("%s",Name);
	p1 = head ; //p1 ָ��ָ��ͷ���
	// �ڵ���û������
	if(head == NULL)
	{
		printf("�ڴ�տ�����û��!\n");
		printf("======================================================================\n");
		return ;
	} 
	//�ڵ���ֻ��һ������
	if(strcmp(Name,p1->name)==0)
	{
		head = p1->next;
		printf("����ɾ���ɹ�!");
		printf("======================================================================\n");
		return ;
	} 
	
	//���Ҷ�Ӧ������
	while(p1!=NULL && (strcmp(Name,p1->name)!=0))
	{
		p2 = p1;
		p1 = p1->next; //ָ��ڵ���� 
	} 
	//ɾ������Ա���ܲ�����
	if(p1 == NULL)
	{
		printf("ɾ������Ա�����ڣ�");
		printf("======================================================================\n");
		return; 
	} 
	//�����Ա������ɾ��
	if(p1->next!=NULL){
		 
		 p1 = p1->next;//p1 �ƶ�����һ��ָ��ڵ�
		 //����ָ��ָ��p1
		 p2->next = p1;
		 printf("ɾ���ɹ�!\n"); 
		 printf("======================================================================\n");
		return;  
	} else{
	     
	     p2->next = NULL;
	     printf("ɾ���ɹ�\n");
	     printf("======================================================================\n");
	     return;
	} 
}
 //��������
void insert()     
{
    int i;
    char named[20];//���������
	stu *p1,*p2,*p3;
	p1 = head;
	p3=(stu *)malloc(sizeof(stu));
	p3->next=NULL;
    printf("\n\t\t\t����������ݡ���\n");
    printf("----------------------------------------------------------------------\n");
    printf("����������ߵ�����:\n");
    //��¼p3 ָ���ֵ 
    input(p3);
    printf("\n����ѡ��\n");
    printf("1.��λ�ò���\t2.βλ�ò���\t3.ǰ��\n");
    printf("���������ѡ��:");
	scanf("%d",&i); 
	//����ͷ��β������ǰ��
	switch(i)
	{
		case 1:
			p3->next=p1;
			head=p3;
			break;
		case 2:
			    while(p1->next!=NULL)
				{
					p2 = p1;
					p1 = p1->next;
				}	
			p1->next = p3;
			break;
		case 3:
		     printf("������������ǰ�壩:");
			 scanf("%s",named);
			 //���Ҷ�Ӧ�����ƽڵ� 
			 while(strcmp(named,p1->name)!=0)
			 {
			 	 p2 = p1;
			 	 p1 = p1->next;
			 }	
			 p2->next=p3;
			 p3->next=p1;
			 break;
	} 
	printf("����ɹ�!\n");
	printf("======================================================================\n");
	return;
}
//�鿴���ݵĺ���
stu * lookdata(stu *p1)     
{
	 printf("\n\t\t\t������ʾ���ݡ���\n");
	 printf("----------------------------------------------------------------------\n");
	 if(p1 == NULL){
	 	 
	 	 printf("--------------------------��������Ŷ~----------------------------------\n");
	 	 return NULL; 
	 } 
	 //��ʾ��Ӧ������ 
	 while(p1!=NULL)
	 {
	 	 printf("����:%s\n",p1->name);
         printf("ѧ��:%s\t",p1->num);
         printf("======================================================================\n");
         p1=p1->next;
	 } 
	 return p1;
} 
////��������ĺ���
stu * inputdata()     //��������ĺ���
{
	stu *p1,*p2;
	int i =1;
	p1 = (stu *)malloc(sizeof(stu));
	//�ڴ�����ʧ��ֱ���˳� 
	if(p1 != NULL)
	{
		 head = p1;
         printf("\n\t\t\t�����������ݡ���\n");
         printf("------------------------------------------------------------------\n");
         printf("�����������롰ok�������������ݽ���\n");
         //��ȡ��������� 
         while(i)
		 {    
		       printf("����:");
		 	   //�ж��Ƿ�����Ҫ����
			   scanf("%s",&p1->name);
			   //�ж��Ƿ���Ҫ����
			   if(strcmp(p1->name,"ok") == 0)
			   {
			   	  printf("\n�������!\n");
                  printf("========================================================================\n");
                  i=0; //�˳���ǰѭ�� 
                  p2->next=NULL; //ָ��Ϊ�� 
                  free(p1); //�ͷ��ڴ� 
                  p1=p2;    // 
			   }
			   else
			   {
			      printf("ѧ��:");
                  scanf("%s",&p1->num);
                  printf("=====================================\n");
                  p2=p1;
                  //Ϊp1���������ڴ� 
                  p1=(stu *)malloc(sizeof(stu));
                  if(p1!=NULL)
                  {
                     p2->next=p1;
                  }
			   } 
		 }
         return(p1->next);
	}
	
} 
//����������� 
void input(stu *p1)
{
	printf("����:");
	scanf("%s",&p1->name);
	printf("ѧ��:");
	scanf("%s",&p1->num);
}

//���˵�
void print()    
{
     system("cls");
     printf("\n\n\n");
     printf("      �������������������������������\n");
     printf("      ***********************************************************\n");
     printf("      \t\t\t�༶ͨѶ¼����ϵͳ\n");
     printf("\n");
     printf("      \t\t1. ��������");
     printf("\t\t2. ��ʾ����\n");
     printf("      \t\t3. ��������");
     printf("\t\t4. ɾ������\n");
     printf("      \t\t5. �鿴����");
     printf("\t\t6. �޸�����\n");
     printf("      \t\t7. ��������");
     printf("\t\t8. �������˵�\n");
     printf("      ***********************************************************\n");
     printf("      ~~~~~��~~~~~~~~~~��~~~~~~~~~~��~~~~~~~~~~��~~~~~~~~~~9~~~~~\n");
    printf("      -----------------------------------------------------------\n\n");
}
//��Ļ��ʾ��������
void screen()
{
	int i;
	//������ʵ���ַ��� 
	char s[251] = {"��ӭʹ����ZM�����༶ͨѶ¼����ϵͳ��\n\n\t\t\t��ϵͳ����ͨѶ¼����----���򣬴�ӡ\n\n\n\t\tWelcome to use produced by ZM class address book\n\n\t\t management system,sorting,printing"};
	printf("\n================================================================================\n");
	printf("\n\n\n\t\t\t");
	//����ʵ������ 
	for(i=0;s[i]!=NULL;i++)
	{
		Sleep(30); 
		printf("%c",s[i]);
	} 
	printf("\n\n\n\n\n\n\n\n\t\t ~ Hi~ o(*������*)��~ ~ ~ף����;���~ ~\n");
    printf("================================================================================\n");
} 

