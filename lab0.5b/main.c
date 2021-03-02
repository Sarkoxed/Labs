#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(){
  list *le_string = NULL, *orig;
  char *temp;
  char *begend = "a b";
  int num = 2;
  /*printf("Begining symbol is: ");
  scanf("%m[^\n]", &begend);
  printf("\n%c %c", begend[0], begend[2]);
  scanf("%*[\n]");
  //scanf("%*[\n]");
  //printf("\n");
  scanf("%*[\n]"); */

  printf("\nYour 1 string: ");

  /*scanf("%m[^\n]", &temp);
  le_string = init(temp[0]);
  orig = le_string;

  initialize(le_string, temp);
  le_string = orig;
  le_string = new_list(le_string, begend[0], begend[2]);*/


  while(scanf("%m[^\n]", &temp) != -1){
    if (strlen(temp) == 0){
      printf("No words found");
    }
    else{
      le_string = init(temp[0]);
      orig = le_string;
      initialize(le_string, temp);
      le_string = orig;

      le_string = new_list(le_string, begend[0], begend[2]);

      if(le_string == NULL){
        printf("There're no pairs of such a symbols in this string\n ");
      }
      else{
        printf("New string is: ");
        print_list(le_string);
      }
   }

    printf("\n#################################################\n");

    printf("Your %d string: ", num++);
    scanf("%*[\n]");

    free(temp);
    free_list(le_string);

  }
  free(temp);

  printf("\n\n\n-------------------Input ended.-------------------\n");

return 0;
}
