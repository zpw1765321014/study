#include <stdio.h>

/**
  ��������ָ�� 
*/ 
double getAverage(int *arr,int size);


int main()
{
	/* ���� 5 ��Ԫ�ص���������  */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
 
   /* ����һ��ָ�������ָ����Ϊ���� */
   avg = getAverage( balance, 5 ) ;
 
   /* �������ֵ  */
   printf("Average value is: %f\n", avg );
    
   return 0;
} 

double getAverage(int *arr, int size)
{
  int    i, sum = 0;       
  double avg;          
  printf("***arr%p\n",&arr);
  for (i = 0; i < size; ++i)
  {  
    printf("ÿ��Ԫ�صĵ�ַ%d\n",arr[i]);
    sum += arr[i];
  }
 
  avg = (double)sum / size;
 
  return avg;
}
