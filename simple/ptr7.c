#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
  ����ָ�뺯�� 
*/

int *getRandom()
{
	static int r[10];
	
	int i;
	/*��������*/
	srand((unsigned)time(NULL)); 
	
	for(i=0;i<10;i++)
	{
	    r[i] = rand();
		printf("%d\n",r[i]);	
	}
	return r; //����Ԫ�ص��׵�ַ 
} 

//����һ��������

int  main()
{
	//����һ��ָ�뺯��
	int *p;
	int i;
	p = getRandom();  //���ص���������׵�ַ  һ�α���  ����ָ�����p�ǿ��Խ��ܵ�  
	for(i=0;i<10;i++)
	{   
	    printf("****%p\n",(p + i)); //�����Ӧ�ĵ�ַ 
		printf("*(p + [%d]) : %d\n", i, *(p + i) );
	}
	return 0; 
} 
