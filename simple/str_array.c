# include <stdio.h>

const int MAX = 3;

int main()
{
	 int var[] = {10,100,200};
	 int i,*ptr;
	 
	 //ptr ָ��Ԫ�ص��׵�ַ
	 /*ptr = var;
	 
	 for(i =0; i< MAX ;i++)
	 {
	 	  printf("�洢��ַ��var[%d] = %p\n", i, ptr );
	 	  
          printf("�洢ֵ��var[%d] = %d\n", i, *ptr );  //ͨ��ָ����ʾ��Ӧ������ 
 
           /* ָ����һ��λ��  //ָ�����Ƹ��ߵ�ǰ���������� ��ѡ���ƶ����ٸ��ֽ� 
         ptr++;
	 } */
	 
	 //ָ��ݼ�����
	 /*ptr = &var[MAX];   //��ȡ���һ��Ԫ�صĵ�ַ 
	 
	 for(i = MAX ;i>0; i--)
	 {
	 	 printf("�洢��ַ��var[%d] = %p\n", i-1, ptr );
	 	 
          printf("�洢ֵ��var[%d] = %d\n", i-1, *ptr );
          
          //ָ������Ľڵ������ƶ�
		  ptr--; 
	 } */
	 ptr = &var;  //��ȡָ���еĵ�һ����ַ
	 i = 0;
	 while(ptr <= &var[MAX-1])
	 {
	 	  printf("�洢��ַ��var[%d] = %p\n", i, ptr );
          printf("�洢ֵ��var[%d] = %d\n", i, *ptr );
 
          /* ָ����һ��λ�� */
          ptr++;  //ָ������ƶ� 
          i++;
	 } 
	 return  0;
}
