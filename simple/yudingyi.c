#include <stdio.h>

# define message_for(a,b)\
   printf(#a " and " #b ": We love you!\n"); 
   
int main()
{
 	/*printf("File :%s\n", __FILE__ );  //��ӡǰ �ļ���λ�� 
    printf("Date :%s\n", __DATE__ );    // ��ǰϵͳ������ 
    printf("Time :%s\n", __TIME__ );    // ��ǰϵͳ��ʱ�� 
    printf("Line :%d\n", __LINE__ );    // �ļ������� 
    printf("ANSI :%d\n", __STDC__ );*/ 
    
    //���õ�Ԥ���ڵĴ�����
	message_for(Carole, Debra); 
	return 0;
}
