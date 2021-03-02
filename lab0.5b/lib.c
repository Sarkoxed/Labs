#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void initialize(list *le_string, char *s){
  for(int i = 1; i < strlen(s); i++){
    le_string = add(le_string, s[i]);
    }
}

int new_list(list *le_string, char b, char e){
  int k = 0;
  list *p;

  while((le_string->el != b)&&(le_string != NULL)){
    le_string = del_root(le_string);
  }
  p = le_string;

  if (le_string == NULL){
    return 0;
  }

  while(le_string != NULL){
    if((le_string->el == b)&&(k == 0)){
      if (le_string == p){
         le_string = del_root(le_string);
         p = le_string;
      }else{
        le_string = del(le_string, p);
      }
      k = 1;
    }

    else if((le_string->el == e)&&(k == 1)){
      le_string = del(le_string, p);
      le_string = add(le_string, ' ');
      k = 0;
    }
    else if(k == 0){
      le_string = del(le_string, p);
    }


    le_string = le_string->next;


  }
  le_string = p;

  return 1;
}


list * init(char x){
  list *a;
  a = malloc(sizeof(list));
  a->el = x;
  a->next = NULL;
  return a;
}


list * add(list *a, char c){
  list *tmp, *p;
  tmp = malloc(sizeof(list));
  p = a->next;                //сохранение указателя на следующий элемент
  a->next = tmp;              //перстановка указателя текущего на добавляемый элемент
  tmp->el = c;                //перстановка указателя на добавляемый элемент
  tmp->next = p;              //установка указателя добавленного элемента на следующий
  return tmp;                //адрес добавленного элемента
}


list * del(list *a, list *orig){
  list *tmp;
  tmp = orig;                  //указатель на начало оригинального

  while(tmp->next != a){       //поиск указателя а
    tmp = tmp->next;
  }

  tmp->next = a->next;         //установка указателя перед а на после а
  free(a);
  return tmp;

}


list * del_root(list *orig){
   list *tmp;
   tmp = orig->next;
   free(orig);
   return tmp;
}


void print_list(list *a){
  list *p;
  p = a;
  while(p != NULL){
    printf("%c", p->el);
    p = p->next;
  }
}


void free_list(list *orig){
  list *p;
  while(orig != NULL){
    p = orig->next;
    free(orig);
    orig = p;
  }
}
