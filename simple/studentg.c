#include <stdio.h>

#define N 3 //�궨�� 

struct student 
{
	int num;
	char name[20];// ѧ������
	float score[3];//ѧ���ɼ�
	float aver;   //ƽ���ɼ� 
}; 
//������ 
int main()
{
	 //��ȡѧ���ɼ�
	 void input(struct student s[]); 
	 //�ṹ�庯�������ֵ
	 struct student max(struct student s[]);//�������� 
	 // ��ӡ����
	 void print(struct student s); 
	 //����ṹ����� 
	 struct student s[N],*p=s;
	 //���ú��� 
     input (p);
     //��ӡ����max������� 
     print(max(p));
     //�������ķ���ֵ 
     return 0;
} 


