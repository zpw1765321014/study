#include <stdio.h>

const int MAX = 3;

int main()
{
	int var[] = {100,200,500};
	
	int i,*ptr[MAX]; //����һ�����͵�ָ������
	
	for(i = 0;i<MAX;i++)
	{
		
		ptr[i] = &var[i]; //��Ԫ�صĵ�ַ��ֵ������ 
	} 
    
    for(i=0;i<MAX;i++)
	{
		printf("Value of var[%d] = %d\n", i, *ptr[i] ); //  ���Ԫ�ص�ַָ���Ԫ�� 
	}
	
	return 0;	
} 
