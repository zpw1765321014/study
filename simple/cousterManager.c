#include <stdio.h>
#include <string.h>

//����ͻ��ṹ�� 
struct Customer {
	int   id;
	int   age;
	char  name[10];
	char  gender;
	char  phone[10];
	char  email[10];
};

int key ;
char loop=1;
int  customerNum=1;
//��ӿͻ� 
void add()
{
	printf("��ӿͻ���Ϣ\n"); 
}
//��ӿͻ� 
void del()
{
	printf("ɾ���ͻ���Ϣ\n"); 
}
//��ӿͻ� 
void showList()
{
	printf("��ʾ�ͻ���Ϣ\n"); 
}
//��ӿͻ� 
void edit()
{
	printf("�޸Ŀͻ���Ϣ\n"); 
}
//������ʾ�˵�
void mainMenu()
{
	do{
		
		printf("\n----------------------�ͻ���ϵ����ϵͳ--------------------------");
		printf("\n                       1 �� �� �� ��                            ");
		printf("\n                       2 �� �� �� ��                            ");
		printf("\n                       3 ɾ �� �� ��                            ");
		printf("\n                       4 �� �� �� ��                            ");
		printf("\n                       5 ��       ��                            ");
		printf("\n                       ��ѡ��(1-5)��_                           ");
		
		//��ȡ��Ӧ����������
		printf("\n������(1-5):");
		scanf("%d",&key); 
		//ѡ���Ӧ�Ĳ�������
		switch(key)
		{
			case 1:
				add(); 
				break;
			case 2:
				edit();
				break;
			case 3:
				del();
				break;
			case 4:
				showList();
				break;
			case 5:
				loop = 0;
				break;
		    default:
		    	printf("��ѡ���ѡ�񲻶�Ŷ");
				break;				
		} 
	}while(loop);
} 
//������ 
void main()
{
	mainMenu();
}
