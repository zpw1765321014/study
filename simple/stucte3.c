#include <stdio.h>

int main()
{
	struct{
		char  *name;
		int   num;
		int   age;
		char  group;
		float score;
	}stu1 ={"Tom",12,8,'A',136.5},*pstu=&stu1; //����ָ��ṹ��
	
	//��ȡ�ṹ���Ա��ֵ
    printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, (*pstu).score);
    printf("%s��ѧ����%d��������%d����%c�飬����ĳɼ���%.1f��\n", pstu->name, pstu->num, pstu->age, pstu->group, pstu->score); 
    
    return 0;
}
