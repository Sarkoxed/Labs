#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "keyspace1.h"
#include "keyspace2.h"

#define msize2 20

int main(int argc, char *argv[]){
    FILE *fp;
    table man;

    char *opt, *key2, *info, *type, *ans;
    unsigned key1;

    int n = 1, rel, z = 1;  // n for input check, rel for releases, z for file, v for vendetta
    Item com;

    key_s2 *tab_search, *p;
    float dub1, dub2;

    printf("HELLO\nI AM YOUR TABLE MAKER!\n");
    printf("I HAVE TWO KEYSPACES\n");
    printf("FIRST: UNSIGNED INTEGERS\n");
    printf("SECOND: STRINGS WITH VARIABLE LENGTH\n");
    printf("IF YOU WANT TO SEE MY OPTIONS - TYPE \'HELP\'\n");

    man = init_table(msize2);
    fp = fopen(argv[1], "r");

    while(1){
      printf("\nWHAT SHELL I DO?\n");
      printf("-> ");

      if(z != 0){
        z++;
        opt = calloc(101, sizeof(char));

        fscanf(fp, "%100s", opt);
        n = 1;
        if(strcmp(opt, "endofile") == 0){
          z = 0;
        }
      }
      else{
        opt = getStr(&n);
      }

      if (n == -1){
        break;
      }

      if(strcmp(opt, "help") == 0){
        options();
      }
      else if(strcmp(opt, "both_search") == 0){

        printf("INSERT FIRST KEY: ");

        if(z != 0){
          z++;
          fscanf(fp, "%d", &rel);
        }
        else if(!getInt(&rel)){
          break;
        }

        key1 = (unsigned int)rel;

        printf("\nINSERT SECOND KEY: ");

        if(z != 0){
          z++;
          key2 = calloc(101, sizeof(char));
          fscanf(fp, "%100s", key2);
        }else{
          key2 = getStr(&n);
        }
        if (n == -1){
          break;
        }
        else if(n == 0){
          printf("WARNING!! WRONG INPUT. CONTINUE.\n");
          continue;
        }

        printf("\n");
        n = search_item(key1, key2, man, &com);
        if(n == 0){
          printf("SEEMS THAT THERE IS NO SUCH A TYPE 1 KEY!\n");
        }
        else if(n == -1){
          printf("SEEMS THAT THERE IS NO SUCH A TYPE 2 KEY\n");
        }
        else{
          printf("THERE IS YOUR ITEM: {%s, %f, %f}\n", com.info_i, com.dub1, com.dub2);
        }

        free(key2);
      }
      else if(strcmp(opt, "add") == 0){
        printf("INSERT FIRST KEY: ");

        if(z != 0){
          z++;
          fscanf(fp, "%d", &rel);
        }
        else if(!getInt(&rel)){
          break;
        }

        key1 = (unsigned int)rel;
        printf("\nINSERT SECOND KEY: ");

        if(z != 0){
          z++;
          key2 = calloc(101, sizeof(char));
          fscanf(fp, "%100s", key2);
        }
        else{
          key2 = getStr(&n);
        }

        if (n == -1){
          break;
        }
        else if(n == 0){
          printf("WARNING!! WRONG INPUT. CONTINUE.\n");
          continue;
        }

        printf("\nINSERT INFO STRING: ");

        if(z != 0){
          z++;
          info = calloc(101, sizeof(char));
          fscanf(fp, "%s", info);
        }
        else{
          info = getStr(&n);
        }

        if (n == -1){
          free(key2);
          break;
        }
        else if(n == 0){
          free(key2);
          printf("WARNING!! WRONG INPUT. CONTINUE.\n");
          continue;
        }

        printf("INSERT FIRST FLOAT: ");
        if(z != 0){
          z++;
          fscanf(fp, "%f", &dub1);
        }
        else if(!getFloat(&dub1)){
          break;
        }
        printf("\n");

        printf("INSERT SECOND FLOAT: ");
        if(z != 0){
          z++;
          fscanf(fp, "%f", &dub2);
        }
        else if(!getFloat(&dub2)){
          break;
        }
        printf("\n");


        printf("\n");

        n = add_el(key1, key2, info, &man, dub1, dub2);
        if(!n){
          printf("THERE IS ALREADY SUCH A TYPE 1 KEY\n");
        }
        else{
          printf("SUCCESSFULLY ADDED NEW ELEMENT\n");
        }
        free(key2);
        free(info);
      }
      else if(strcmp(opt, "both_delete") == 0){
        printf("INSERT FIRST KEY: ");

        if(z != 0){
          z++;
          fscanf(fp, "%d", &rel);
        }
        else if(!getInt(&rel)){
          break;
        }

        key1 = (unsigned int)rel;
        printf("\nINSERT SECOND KEY: ");

        if(z != 0){
          z++;
          key2 = calloc(101, sizeof(char));
          fscanf(fp, "%100s", key2);
        }
        else{
          key2 = getStr(&n);
        }

        if (n == -1){
          break;
        }
        else if(n == 0){
          printf("WARNING!! WRONG INPUT. CONTINUE.\n");
          continue;
        }
        printf("\n");
        del_el(key1, key2, &man);

        free(key2);
      }
      else if(strcmp(opt, "get_one") == 0){
        printf("INSERT THE TYPE OF KEY(uns/str): ");

        if(z != 0){
          z++;
          type = calloc(101, sizeof(char));
          fscanf(fp, "%100s", type);
        }else{
          type = getStr(&n);
        }

        if (n == -1){
          break;
        }
        else if(n == 0){
          printf("WARNING!! WRONG INPUT. CONTINUE.\n");
          continue;
        }
        printf("\n");
        if (strcmp(type, "str") != 0 && strcmp(type, "uns") != 0){
          free(type);
          printf("WARNING! NO SUCH AN OPTION. CONTINUE\n");
          continue;
        }

        if(strcmp(type, "uns") == 0){
          printf("INSERT KEY: ");

          if(z != 0){
            z++;
            fscanf(fp, "%d", &rel);
          }
          else if(!getInt(&rel)){
            free(type);
            break;
          }

          key1 = (unsigned int)rel;

          printf("\n");
          n = search_uns(man, key1, &com);
          if(!n){
            printf("NO SUCH A KEY 1 FOUND\n");
          }
          else{
            printf("THERE\'S YOUR ITEM: {%s, %f, %f}", com.info_i, com.dub1, com.dub2);
          }
        }

        else if(strcmp(type, "str") == 0){
          printf("INSERT KEY: ");

          if(z != 0){
            z++;
            key2 = calloc(101, sizeof(char));
            fscanf(fp, "%100s", key2);
          }
          else{
            key2 = getStr(&n);
          }

          if (n == -1){
            free(type);
            break;
          }
          else if(n == 0){
            free(type);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          printf("DO YOU WANT TO SEARCH FOR SPECIFIC RELEASE?(y/n): ");

          if(z != 0){
            z++;
            ans = calloc(101, sizeof(char));
            fscanf(fp, "%100s", ans);
          }else{
           ans = getStr(&n);
          }

          printf("\n");
          if (n == -1){
            free(type);
            free(key2);
            break;
          }
          else if(n == 0){
            free(type);
            free(key2);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          if(strcmp(ans, "y") != 0 && strcmp(ans, "n") != 0){
            free(type);
            free(key2);
            free(ans);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          if(strcmp(ans, "y") == 0){
            printf("INSERT RELEASE NUMBER: ");

            if(z != 0){
              z++;
              fscanf(fp, "%d", &rel);
            }
            else if (!getInt(&rel)){
              free(type);
              free(key2);
              break;
            }

          }
            else{
              rel = 0;
            }
            printf("\n");


          tab_search = search_str(man, key2, rel);
          if(!tab_search){
            printf("NO SUCH A KEY 2 FOUND\n");
          }
          else{
            if(rel == 0){
              printf("YOUR ITEMS: ");
              print_keyspace_2(tab_search);

              while(tab_search){
                p = tab_search;
                tab_search = tab_search->next;
                free(p);
              }
            }

            else{
              printf("THERE\'S YOUR ITEM: ");
              printf("{%s, %f, %f}\n", tab_search->info->info_i, tab_search->info->dub1, tab_search->info->dub2);
            }
          }

          free(key2);
          free(type);
      }

    }
      else if(strcmp(opt, "del_one") == 0){
        printf("INSERT THE TYPE OF KEY(uns/str): ");

        if(z != 0){
          z++;
          type = calloc(101, sizeof(char));
          fscanf(fp, "%100s", type);
        }else{
          type = getStr(&n);
        }

        if (n == -1){
          break;
        }
        else if(n == 0){
          printf("WARNING!! WRONG INPUT. CONTINUE.\n");
          continue;
        }

        printf("\n");
        if (strcmp(type, "str") != 0 && strcmp(type, "uns") != 0){
          free(type);
          printf("WARNING! NO SUCH AN OPTION. CONTINUE\n");
          continue;
        }

        if(strcmp(type, "uns") == 0){
          printf("INSERT KEY: ");

          if(z != 0){
            z++;
            fscanf(fp, "%d", &rel);
          }
          else if(!getInt(&rel)){
            free(type);
            break;
          }

          key1 = (unsigned int)rel;
          printf("\n");
          del_uns(&man, key1);
        }
        else if(strcmp(type, "str") == 0){
          printf("INSERT KEY: ");

          if(z != 0){
            z++;
            key2 = calloc(101, sizeof(char));
            fscanf(fp, "%100s", key2);
          }else{
            key2 = getStr(&n);
          }

          if (n == -1){
            free(type);
            break;
          }
          else if(n == 0){
            free(type);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          printf("DO YOU WANT TO DELETE SPECIFIC RELEASE?(y/n): \n");

          if(z != 0){
            z++;
            ans = calloc(101, sizeof(char));
            fscanf(fp, "%100s", ans);
          }
          else{
            ans = getStr(&n);
          }

          if (n == -1){
            free(type);
            free(key2);
            break;
          }
          else if(n == 0){
            free(type);
            free(key2);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          if(strcmp(ans, "y") != 0 && strcmp(ans, "n") != 0){
            free(type);
            free(key2);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          printf("\n");

          if(strcmp(ans, "y") == 0){
            printf("INSERT RELEASE: ");

            if(z != 0){
              z++;
              fscanf(fp, "%d", &rel);
            }
            else if (!getInt(&rel)){
              free(type);
              free(key2);
              break;
            }

          }
            else{
              rel = 0;
            }

          del_str(&man, key2, rel);

          free(key2);
        }

        free(type);

        }
      else if(strcmp(opt, "show") == 0){
          printf("DO YOU WANT ME TO SHOW YOUR KEYSPACES?(y/n): ");

          if(z != 0){
            z++;
            ans = calloc(101, sizeof(char));
            fscanf(fp, "%100s", ans);
          }else{
            ans = getStr(&n);
          }

          printf("\n");
          if (n == -1){
            break;
          }
          else if(n == 0){
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }

          if(strcmp(ans, "y") != 0 && strcmp(ans, "n") != 0){
            free(ans);
            printf("WARNING!! WRONG INPUT. CONTINUE.\n");
            continue;
          }
          n = 0;
          if(strcmp(ans, "y") == 0){
             n = 1;
          }
          printf("\n");
          show_table(man, n);

          free(ans);
        }
      else if(strcmp(opt, "exit") == 0){
          printf("GOODBYE, SEE YA!\n");
          free(opt);
          break;
        }
      else{
          printf("I DO NOT UNDERSTAND WHAT DO YOU WANT FOR ME\n");
          printf("PLEASE TRY AGAIN OR TYPE \'HELP\'\n");
        }

      if(opt){
        free(opt);
      }
    }

      free_table(&man);

      return 0;
    }


    /* l = (char **)calloc(4, sizeof(char *));
    for(int i = 0; i < 4; i++){
      scanf("%[^\n]m", (l+i));
      scanf("%*c");
    } */
