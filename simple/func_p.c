#include <stdio.h>

int Max();  //�������� 

//  int(*p)(int, int);  ��������������Ǹ�ָ�� ָ���Ϊ���� ���ص�����Ϊ���� 
int main()
{   
     
    int (*p)(int,int);  //����һ������ָ�� 
	
	int a,b,c;
	
	p = Max;  //ָ��p ָ�������׵�ַ 
	
	printf("please enter a and b:");
	
    scanf("%d%d", &a, &b);
	
	c = (*p)(a, b);  //ͨ������ָ�����Max����
	
    printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    
	return 0;
}

//���غ��������ֵ 
int Max(int x,int y)
{
	return x > y ? x : y; 
} 
