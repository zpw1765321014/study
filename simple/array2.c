# include <stdio.h>

void change(int b[]){
	b[0] = 100;  //����һ���ڴ� 
}

int main()
{
    
    int a[4] = {1,2,3,4};
    //������a ���� change��������
	change(a);
	//�鿴����a[0]��ֵ
	printf("a[0]=%d",a[0]); 
    return 0;
		
} 
