#include <stdio.h>

int max(int a,int b)
{
	return a > b ? a:b;
}

int main()
{
	//p ��ָ�뺯��
	int (*p)(int,int) = &max;//&����ʡ��
	int a,b,c,d;
	
	printf("��������������:");
	scanf("%d %d %d",&a,&b,&c);
	
	d = p(p(a,b),c);
	
	printf("����������:%d\n",d);
	return 0; 
}
