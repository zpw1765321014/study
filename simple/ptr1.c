#include <stdio.h>

int main()
{
	int var_runoob = 10;
	
	int *p; //����һ���������͵�ָ����� 
	
	p = &var_runoob; // ָ�����p  ��ȡ  var_runoob �ĵ�ַ
	
    printf("var_runoob �����ĵ�ַ�� %p\n", p);
    
    //����ָ�������ֵ
	printf("*p ��ֵ�� %d\n",*p); 
	
	/***************ָ��Ĭ��ΪNULL********************/
	int *p3 = NULL;
	
	printf("p3 �ĵ�ַ��%p\n",p3);
	return 0; 
	
}
