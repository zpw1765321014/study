#include <stdio.h>

/**
  ָ�뺯�������� 
*/
void test(int *p);

int main()
{
	int num = 90;
	int *p;
	
	p = &num;
	test(&num); //����������ĵ�ַ 
	
	test(p);
	
	printf("num is:%d\n",num);
}

void test(int *p)
{
	*p+=1;
}
