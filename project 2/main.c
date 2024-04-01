#include "func.h"
//#include "func.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 메인 파일 */

void main()
{
  printf("도서관리 프로그램 시작\n");

  login();
  headnode* h = createHead();
  while(1)
  {
    int btn1 = -1;

    printf("--[ 도서 관리 시스템 ]--\n");
    printf("******** 메 뉴 ********\n");
    printf("1. 도서 등록 2. 도서 검색 및 대여 3. 도서 삭제 4. 도서 출력 5. 반납 0. 종료 \n");
    printf("원하는 기능의 번호를 입력해주세요. >> ");
    //rewind(stdin);  // 입력 버퍼 비우기
    scanf("%d", &btn1);
    while(getchar() != '\n');
    printf("\n");

    if(btn1 == 1)
    {
      printf("-----[ 도서 등록 ]-----\n");
      buyBook(h);
      printf("------------------------\n");
      printf("[도서 등록 완료]\n\n");
    }
    else if(btn1 == 2)
    {
      int btn2;
      int searchResult = 0;
      char search[50];

      printf("---[ 도서 검색 및 대여 ]---\n");
      showAllBook(h);
      printf("1. 도서명 2. 저자 3. 출판사 4. 뒤로가기\n");
      printf("검색 형식의 번호를 입력해주세요. >> ");
      scanf("%d", &btn2);
      if(btn2 == 1)   // 도서명으로 검색
      {
       printf("검색하고 싶은 도서명 : ");
       scanf("%s", search);
       searchResult = searchBookTitle(h, search);
      }
      else if(btn2 == 2)
      {
        printf("검색하고 싶은 저자명 : ");
        scanf("%s", search);
        searchResult = searchBookAuthor(h, search);
      }
      else if(btn2 == 3)
      {
        printf("검색하고 싶은 출판사 : ");
        scanf("%s", search);
        searchResult = searchBookPublisher(h, search);
      }
      else if(btn2 == 4)
      {
        continue;
      }
      printf("----- 검색 결과 -----\n");
      if (searchResult == 0) printf("검색 결과가 없습니다.\n\n");
      else printf("해당 도서 수 : %d권\n\n", searchResult);
    }
    else if (btn1 == 3)
    {
      int btn3;
      printf("-----[ 도서 삭제 ]-----\n");
      printf("1. 선택 삭제 2. 전체 삭제 3. 뒤로가기\n");
      scanf("%d", &btn3);

      if(btn3 == 1){        // 선택 삭제
        int del = 0;
        int delResult;
        showAllBook(h);
        printf("삭제하고 싶은 도서 번호 : ");
        scanf("%d", &del);
        delResult == deleteBook(h, del);
        if(delResult == 0) printf("[ 도서 번호가 잘못 입력되었습니다. ]\n\n");
        else printf("[ 삭제 완료 ]\n\n");
      }
      else if(btn3 == 2){       // 전체 삭제
        char btn4;
        printf("정말 모든 도서를 삭제하시겠습니까?(Y/N)\n");
        scanf(" %c", &btn4);
        if(btn4 >= 'a' && btn4 <= 'z') btn4 -= 32;
        if(btn4 == 'Y'){
          deleteAll(h);
          printf("[ 모든 도서가 삭제되었습니다. ]\n\n");
          }
      }
      else if(btn3 == 3){
        continue;
      }
    }

    else if (btn1 == 4)     // 도서 출력
    {
      printf("-----[ 도서 출력 ]-----\n");
      showAllBook(h);
    }
    else if (btn1 == 5)     // 도서 반납
    {
      printf("-----[ 도서 반납 ]-----\n");
      int reBookList = showRentBook(h);
      int snum;
      int btn5;
      if (reBookList == 0)
      {
        printf("현재 대여중인 도서가 없습니다. \n\n");
        continue;
      }
      while(1){
        printf("1. 선택 도서 반납 2. 전체 도서 반납 3.뒤로가기\n");
        printf("원하는 기능을 선택해주세요 >> ");
        scanf("%d", &btn5);
        if(btn5 == 1){
          int returnRes = returnBook(h);
          if (returnRes = 1){
            printf("[ 도서가 성공적으로 반납처리 되었습니다. ]\n\n");
            break;
            }
          else printf("[ 도서 번호가 잘못 입력되었습니다. ]\n\n");
        }
        else if(btn5 == 2){
        returnAll(h);
        printf("[모든 도서를 반납하였습니다.]\n\n");
        break;
        }
        else if(btn5 == 3) break;
        else{
        printf("잘못된 번호를 선택하였습니다.\n");
        continue;
        }
        }
    }
    else if (btn1 == 0)
    {
      break;
      memoryDel(h);
    }
    else printf("0~5의 정수를 입력해주세요.\n");
  }
  printf("---[프로그램 종료]---\n");
}


