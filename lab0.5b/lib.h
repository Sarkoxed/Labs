#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
    char el;
    struct list *next;
}list;

list * init(char x);
list * add(list *a, int n);
list * del(list *a, list *orig);
list * del_root(list *orig);
void print_list(list *a);
