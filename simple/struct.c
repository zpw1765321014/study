#include <stdio.h>

int main()
{   
    //����ṹ�� 
	struct{
		
		char *name;
		int num;
		int age;
		char group;
		float score;
		
	} stu1,stu2 = {"Tom", 12, 18, 'A', 136.5};
    
	//���ṹ�帳ֵ
	stu1.name = "С��";
	stu1.num  = 12;
	stu1.age  = 26;
	stu1.group = 'A';
	stu1.score = 99.5;
	//��ȡ�ṹ���ֵ 
	printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);
	printf("\n"); 
	printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", stu2.name, stu2.num, stu2.age, stu2.group, stu2.score);
} 
