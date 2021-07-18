#include <stdio.h>
#include <stdlib.h>

//������Ӧ�����ݱ�ṹ
typedef struct Table{
	
	 int *head;// //������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
	 int length; //��¼��ǰ˳���ĳ���
	 int size; // ��¼˳���Ĵ洢���� 
	 
} table; 

#define Size 5

//gcc c89 for ֻ������������Ȼ����ִ�� 
table initTable(){
	table t;
	t.head = (int*)malloc(Size*sizeof(int)); // /����һ���յ�˳�����̬����洢�ռ�
	//�������ʧ������������ʾ Ȼ���˳�
	
	if(!t.head){
		
		printf("��ʼ��ʧ��");
		exit(0); 
	} 
	
	t.length =0; //�ձ�ĳ��ȳ�ʼ��Ϊ0
	t.size  = Size;  //�ձ�ĳ�ʼ�洢�ռ�ΪSize
	return t;
}
//���˳������
table addTable(table t,int elem,int add){
      
	    //�ж�λ���Ƿ���ȷ
		if(add > t.length+1 || add <1){
			
			 printf("����λ��������\n");
			 
			 return t;
		}
		
		//���·����ڴ�
		if(t.length > t.size){
			 
			  t.head=(int *)realloc(t.head, (t.size+1)*sizeof(int));
			  if(!t.head){
			  	  
			  	   printf("��ȡ����ʧ��\n");
			  }
			  t.size+=1;
		}	
		
		//�����Ӧ������  ָ����λ��������Ӧ��ֵ ������ȫ������
		int i;
		for (i=t.length-1;i>add-1;i--){
			  t.head[i+1] = t.head[i];
		}
		//���Ƶ�ǰ������λ��
		t.head[add] =  elem;
		t.length++; // ���ȼ� 1 
		 
} 
//ɾ����Ӧ������
table delTable(table t,int add){
	  
	   //�ж�ɾ���������Ƿ����
	   if(t.length<add || add < 1){
	   	    
	   	    printf("ɾ��������λ���д���!");
	   	    return t;
	   } 
	   int i;
	   for(i=add;i<t.length;i++){
	   	   t.head[i-1] = t.head[i];
	   }
	   t.length--;
	   return t;
} 
//���Ҷ�Ӧ��Ԫ��
int selectTable(table t,int elem){
	
	  int i;
	  for(i=0;i<t.length;i++){
	  	   
	  	     	 
	  	  if(t.head[i] == elem){
	  	    	      
			  return i+1;  	
			}
			
	  }
	  return -1;
} 
//�޸Ķ�Ӧ��Ԫ��
table amendTable(table t,int elem,int newElem){
	  
	   //��ȡ��ӦԪ�ص��±�
	   int add =  selectTable(t,elem);
	   if(add == -1){
	   	    
	   	    printf("��������!\n");
	   }
	   t.head[add-1]=newElem;
	   return t;
} 
//���˳�����Ԫ�صĺ���
void displayTable(table t){
	int i;
    for (i=0;i<t.length;i++) {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}

//��ں���
int main(){
   
   table t = initTable();
   //��˳����� �������
   int i;
   for(i=1;i<=Size;i++){
   	   
   	    t.head[i-1]=i;
   	    t.length++;
   } 
    printf("˳����д洢��Ԫ�طֱ��ǣ�\n");
    displayTable(t);
    
    printf("ɾ��Ԫ��1:\n");
    t =delTable(t, 1);
    displayTable(t);
    
    printf("�ڵ�2��λ�ò���Ԫ��5:\n");
    t = addTable(t, 5, 2);
    displayTable(t);
    
    printf("����Ԫ��3��λ��:\n");
    int add=selectTable(t, 3);
    printf("%d\n",add);
    
    //�޸�
	printf("��Ԫ��3��Ϊ6:\n");
    t=amendTable(t, 3, 6);
    displayTable(t); 
    return 0;
} 







