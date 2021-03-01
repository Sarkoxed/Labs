#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_strings(char *a, char *b, char *temp);
void new_words(char *word, char *a,int *a_timer, char *b, int *b_timer);
void check_cal(char *t);

void check_cal(char *t){
  if(t == NULL){
    printf("You need more ram");
  }
}

void new_words(char *word, char *a,int *a_timer, char *b, int *b_timer){
  int len = strlen(word);
  char prev, cur;
  prev = ' ';

  for(int i = 0; i < len; i++){
    cur = word[i];

    if(cur != prev){
      a[*a_timer] = cur;
      *a_timer += 1;
    }
    else{
      b[*b_timer] = cur;
      *b_timer += 1;
    }
    prev = cur;
  }
}

void new_strings(char *a, char *b, char *temp){

  int gap_count = 0, a_timer = 0, b_timer = 0, temp_timer = -1, ch = ' ', n;
  char *p, *word;

  while(temp[gap_count] == ' '){
    gap_count++;
  }

  temp += gap_count;

  while(strlen(temp) > 0){

    p = strchr(temp, ch) + 1;

    n = strlen(temp) - strlen(p);

    word = calloc(n, sizeof(char));
    strncpy(word, temp, n - 1);

    temp_timer = b_timer;
    new_words(word, a, &a_timer, b, &b_timer);

    a[a_timer++] = ' ';

    if(temp_timer != b_timer){
      b[b_timer++]=' ';
    }

    temp = p;
    gap_count = 0;

    free(word);

    while(temp[gap_count] == ' '){
      gap_count++;
    }

    temp += gap_count;
  }

}


int main(){
  char *temp, *temp1, *new_string, *repeated;
  int n, num = 2;

  printf("Your 1 string: ");

  while(scanf("%m[^\n]", &temp) != EOF){
    check_cal(temp);
    n = strlen(temp);

    temp1 = calloc(strlen(temp)+2, sizeof(char));
    check_cal(temp1);

    strcat(temp1, temp);
    temp1[strlen(temp)] = ' ';                     //appending gap to temp
    free(temp);

    new_string = calloc(n + 1,sizeof(char));
    check_cal(new_string);
    repeated = calloc(n + 1,sizeof(char));
    check_cal(repeated);


    new_strings(new_string, repeated, temp1);

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
    free(temp1);
    free(repeated);
    free(new_string);
    printf("Your %d string: ", num++);
    scanf("%*[\n]");

  }
  free(temp);

  printf("\n\n\n-------------------Input ended.-------------------\n");

return 0;
}
