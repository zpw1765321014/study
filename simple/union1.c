#include <stdio.h>
#include <stdlib.h>

#define TOTAL 4
/**
  �ṹ��ĸ�����Ա��ռ�ò�ͬ���ڴ棬����֮��û��Ӱ�죻
  ������������г�Առ��ͬһ���ڴ棬�޸�һ����Ա��Ӱ���������г�Ա
*/ 
struct{
	char name[20];
	int  num;
	char sex;
	char profession;
	//������ 
	union{
		 
		  float score;
		  char  course[20]; 
	}sc;
	
}bodys[TOTAL];

int main(){
	
	int i;
	//������Ա��Ϣ
	for(i=0;i<TOTAL;i++){
		
		printf("Input info:");
		scanf("%s %d %c %c", bodys[i].name, &(bodys[i].num), &(bodys[i].sex), &(bodys[i].profession));
        if(bodys[i].profession == 's'){  //�����ѧ��
            scanf("%f", &bodys[i].sc.score);
        }else{  //�������ʦ
            scanf("%s", bodys[i].sc.course);
        }
        fflush(stdin); //ˢ����Ļ������ 
	} 
	
	//�����Ա��Ϣ
    printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
    
    for(i=0; i<TOTAL; i++){
    	
        if(bodys[i].profession == 's'){  //�����ѧ��
            printf("%s\t%d\t%c\t%c\t\t%f\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.score);
        }else{  //�������ʦ
            printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.course);
        }
        
    }
    return 0;
}
