#include <stdio.h>

#define NAME_LENGTH 32
//属性
struct student{
     
     const void *_;
     int age;
     char name[NAME_LENGTH];
      
}
//方法
struct func{
       
       size_t size;
       void (*ctor)(void *self,va_list *params);
       void* (*dtor)(void *self);

       void  (*set_age)(int age);
       int   (*get_age)(int age);
       void  (*set_name)(char *name);
       char  (*get_name)(void);
}

void *New(const void *class,...){

}

void Delete(void *class){

}