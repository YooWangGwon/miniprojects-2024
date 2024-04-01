#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 메 인 파 일 */

void main()
{
  printf("도서관리 프로그램 시작\n");

  login();
  headnode* h = createHead();
  printf("--[ 도서 관리 시스템 ]--\n");

  while(1)
  {
    int btn1 = showMenu();
    while(getchar() != '\n');
    printf("\n");

    if(btn1 == 1)           // 도서 구매(등록)
    {
      buyBook(h);
    }
    else if(btn1 == 2)      // 도서 검색 및 대여
    {
      searchBook(h);
    }
    else if (btn1 == 3)     // 도서 삭제
    {
      deleteBook(h);
    }

    else if (btn1 == 4)     // 도서 출력
    {
      showAllBook(h);
    }

    else if (btn1 == 5)     // 도서 반납
    {
      returnBook(h);
    }
    else if (btn1 == 0)     // 프로그램 종료
    {
      break;
      memoryDel(h);
    }
    else printf("0~5의 정수를 입력해주세요.\n");
  }
  printf("---[프로그램 종료]---\n");
}
