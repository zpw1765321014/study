#include <stdio.h>

int main()
{

    
    // ����һ������
	// ����һ��int���͵�����
	 int a[4] = {1, 2, 3, 4};
	
	 int *p = a;
	 
	 int i;
	 //for (i = 0; i < 4; i++) {
	 //    printf("a[%d] = %d \n", i, a[i]);
	 //} 
	 printf("����ָ����ʾ����\n");
	 //��ָ���������
	 for(i=0 ;i<4;i++){
	 	
	 	//����ָ��*ȡ�����ݵ�ֵ
		 int value = *(p++);  // p+1 ������int ����ָ���ƶ� 4��Ϊ ���� 4���ֽ� 
		 printf("a[%d] = %d \n", i, value);
	 } 
	return 0;
}
