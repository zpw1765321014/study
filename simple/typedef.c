#include <stdio.h>
#include <string.h>

typedef struct Books {
	
	 char title[50];
	 char author[50];
	 char subject[100];
	 int  book_id;
}Book;

int main(){
	 
	 Book book;
	   //printf( "%p\n", &book);
	  //printf( "%p\n", book.author);
	 strcpy(book.title,"C �̳�");   // strcpy ���ַ������и���  ��Ϊ �ṹ������  ��������bai����̬��ֵַ��du���ܱ��޸ģ�\
	                                //���zhi������ݴ洢�����У���
	                                // ������memcpy�������������ڴ濽���������ѭ�����и�ֵ
	 strcpy( book.author, "Runoob"); 
     strcpy( book.subject, "�������");
     // book.subject = "�������";
     book.book_id = 12345;  //����ֱ�Ӹ�ֵ�ṹ���ַ��� 
     
     printf( "����� : %s\n", book.title);
     printf( "������ : %s\n", book.author);
     printf( "����Ŀ : %s\n", book.subject);
     printf( "�� ID : %d\n", book.book_id);
    
    return 0;
}
