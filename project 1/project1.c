#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024
void main()
{
  char ID[] = "qwer1234";
  char PS[] = "qwer1234";
  char id[SIZE];
  char ps[SIZE];
  char msg1[SIZE];
  FILE* fd;

  while(1)
  {
    printf("PROJECT 01\n");
    printf("아이디와 비밀번호를 입력하시오.\n");
    printf("ID:");
    scanf("%s",id);
    printf("PASSWORD:");
    scanf("%s",ps);

    int id_result = strcmp(ID,id);
    int ps_result = strcmp(PS,ps);
    if(id_result==0 && ps_result==0)
    {
      fd = fopen("myinfo.txt","r");
      if(fd == NULL)
      {
        fprintf(stderr, "open() error!");
        exit(1);
      }

      printf("-----정보출력-----\n");
      while(fscanf(fd, "%s", msg1) != EOF)
      {
        printf("%s\n",msg1);
      }

      printf("-----출력끝-----\n");

      fclose(fd);
      break;
    }
  else printf("아이디나 비밀번호가 불일치합니다.");
  }
}
