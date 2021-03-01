#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


list * init(char x){
  list *a;
  a = malloc(sizeof(list));
  a->el = x;
  a->next = NULL;
  return(a);
}

list * add(list *a, int n){
  list *tmp, *p;
  tmp = malloc(sizeof(list));
  p = a->next;
  a->next = n;
  tmp->next = p;
  return(tmp);
}

list * del(list *a, list *orig){
  list *tmp;
  tmp = orig;
  while(tmp->next != a){
    tmp = tmp->next;
  }
  tmp->next = a->next;
  free(a);
  return(tmp);

}

list * del_root(list *orig){
   list *tmp;
   temp = orig->next;
   free(orig);
   return(tmp);
}

void print_list(list *a){
  list p;
  p = a;
  while(p != NULL){
    printf("%c", a->el);
    p = p->next;
  }
}
