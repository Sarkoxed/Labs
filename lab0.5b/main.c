#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list * init



typedef struct list{
    char el;
    struct list *next;
}list;

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

void new_strings(char *a, char *b, char *c, int len);


void new_strings(char *a, char *b, char *c, int len){
  char prev, temp;
  int k = 0, l = 0, r = 1, t1 = 0, t2 = 0;

  // k - first non gap, l - gap dublication
  // r - dublications, t_i - timers for strings

  while(c[k] == ' '){
      k++;
  }

  prev = ' ';



}


int main(){
  char *temp, *new_string, *repeated;
  char start, end;
  int n, num = 2;
  printf("Symbols are: ");
  scanf()
  printf("Your 1 string: ");

  while(scanf("%m[^\n]", &temp) != -1){
    n = strlen(temp);
    new_string = calloc(n,sizeof(char));
    repeated = calloc(n,sizeof(char));

    new_strings(new_string, repeated, temp, n);

    if(strlen(new_string) > 0){
      printf("\nNew string, without dublication: %s", new_string);
    }
    else{
      printf("\nNo words Found in original string");
    }
    if(strlen(repeated) > 0){
    printf("\nAll Dublications:                %s\n", repeated);    }
    else{
      printf("\nNo Dublications Found");
    }

    printf("\n#################################################\n");
    free(temp);
    free(repeated);
    free(new_string);
    printf("Your %d string: ", num++);
    scanf("%*[\n]");

  }
  free(temp);

  printf("\n\n\n-------------------Input ended.-------------------\n");

return 0;
}
