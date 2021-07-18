#include <stdio.h>
#include <stdlib.h>

//�ص�����
void populate_array(int *array,size_t arraySize,int (*getNextValue)(void))   //�����������Ǻ���ָ�� 
{   
    size_t i;
	for(i= 0;i<arraySize;i++){
		
		  array[i] = getNextRandomValue();
	} 
}
//��ȡ���ֵ
int getNextRandomValue()
{
	return rand();//��ȡ����� 
}
//������ 
int  main(void)
{
	int myarray[10];
	
	populate_array(myarray,10,getNextRandomValue);
	int i;
	for(i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
} 
