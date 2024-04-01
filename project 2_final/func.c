#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 함 수 파 일 */

headnode* createHead()
{
  headnode* h = malloc(sizeof(book));
  h -> head = NULL;
  return h;
}

void login()
{
  //char ID[] = "qwer1234";
  //char PS[] = "asdf1234";
  //char Uid[20];
  //char Ups[20];
  char uid[20];
  char ups[20];
  char newid[20];
  char newps[20];
  char conps[20];
  int select1;
  int select2;
  info list[20];
  info* user = list;
  int i = 0;

  while(1)
  {
    printf("1. 로그인 2. 회원가입\n");
    printf("원하는 기능을 선택하세오. >> ");
    scanf("%d", &select1);

    if(select1 == 1){   // 로그인
      printf("[ 로그인 ]\n");
      FILE* fd1;
      fd1 = fopen("user.txt","r");    // "읽기"로 유저 정보 파일 오픈
      if(fd1 == NULL){
        fprintf(stderr, "r open() error!!");
        exit(1);                      // 파일 오픈에 에러 발생시 에러 문구와 >
      }

      printf("ID : ");
      scanf("%s", uid); // 아이디 입력
      printf("PASSWORD : ");
      scanf("%s", ups); // 비밀번호 입력


      while(fscanf(fd1, "%s %s", user->id, user->ps) != EOF){

        int id_result = strcmp(user->id, uid);
        int ps_result = strcmp(user->ps, ups);
        if(id_result == 0 && ps_result == 0){
          printf("%s님 환영합니다\n\n", uid);
          return;
        }
      }

      fclose(fd1);

      printf("아이디나 비밀번호가 불일치합니다\n");
      printf("1.로그인 재시도 2. 프로그램 종료\n");
      scanf("%d", &select2);
      while(1)
      {
        if(select2 == 1) break;
        else if(select2 == 2){
        printf("도서관리 프로그램 종료\n");
        exit(0);
        }
        else{
        printf("숫자를 다시 선택해 주세요.\n");
        continue;
        }
      }
    }

    else if(select1 == 2){    // 회원가입
      printf("[ 회원가입 ]\n");
      FILE* fd2;
      fd2 = fopen("user.txt","a+");
      if(fd2 == NULL)
      {
        fprintf(stderr, "w open() error!\n");
        exit(1);
      }

      printf("아이디(영문, 숫자만 가능) : ");
      scanf("%s",newid);
      printf("비밀번호(영문, 숫자만 가능) : ");
      scanf("%s",newps);

      while(1){
        printf("비밀번호 확인 : ");
        scanf("%s",conps);
        int conresult = strcmp(newps, conps);
        if(conresult == 0) break;
        else{
          printf("비밀번호를 잘못 입력하셨습니다.\n");
          continue;
        }
      }
      fprintf(fd2, "%s\n%s\n", newid, conps);
      fclose(fd2);
    }
  }
}

int showMenu()
{
  int result;
  printf("\n*******메뉴*******\n");
  printf("1. 도서 등록\n");
  printf("2. 도서 검색 및 대여\n");
  printf("3. 도서 삭제\n");
  printf("4. 도서 출력\n");
  printf("5. 도서 반납\n");
  printf("0. 프로그램 종료\n");
  printf("*******************\n");
  printf("원하는 기능의 번호를 입력해주세요. >> ");
  scanf("%d", &result);
  printf("\n");
  return result;
}

static int bnum = 0;
void buyBook(headnode* h)
{
  printf("-----[ 도서 등록 ]-----\n");
  book* newBook = malloc(sizeof(book));
  newBook->booknum = ++bnum;
  printf("도서명 : ");
  scanf("%s", newBook->title);
  printf("가격 : ");
  scanf("%d", &(newBook->price));
  printf("저자 : ");
  scanf("%s", newBook->author);
  printf("출판사 : ");
  scanf("%s", newBook->publisher);
  newBook->rental = 'Y';
  newBook->next = NULL;

  book* temp = h -> head;
  if(h->head != NULL)
  {
    while ( temp->next != NULL)
    {
      temp = temp -> next;
    }
    temp->next = newBook;
  }
  else h->head = newBook;
  printf("-----------------\n");
  printf("[ 도서 등록 완료 ]\n\n");
}

void showAllBook(headnode* h)
{
  printf("-----[ 도서 출력 ]-----\n");
  book* temp = h->head;
  if( h->head != NULL)
  {
    while (temp != NULL)
    {
      printf("-----------------\n");
      printf("도서 번호 : %d\n", temp->booknum);
      printf("도서명 : %s\n", temp->title);
      printf("가격 : %d\n", temp->price);
      printf("저자 : %s\n", temp->author);
      printf("출판사 : %s\n", temp->publisher);
      printf("대여 가능 여부 : %c\n", temp->rental);
      temp = temp -> next;
    }
    printf("-----------------\n\n");
  }
  else printf("현재 등록된 도서가 없습니다.\n\n");
}

void searchBook(headnode* h)
{
  int btn2;
  char search[50];
  int result = 0;
  char rent;
  printf("---[ 도서 검색 및 대여 ]---\n");
  showAllBook(h);
  if(h->head != NULL){
    while(1){
      printf("1. 도서명 2. 저자 3. 출판사 4. 뒤로가기\n");
      printf("검색 형식의 번호를 입력해주세요. >> ");
      scanf("%d", &btn2);
      while(getchar() !=  '\n');

      if(btn2 == 1)     // 도서명으로 검색
      {
        printf("검색하고 싶은 도서명 : ");
        scanf("%s", search);
        book* temp = h->head;
        while ( temp != NULL)
        {
          if(strcmp(search, temp-> title) == 0)
          {
            if(temp->rental = 'Y')
            {
              printf("대여하시겠습니까?(Y/N) >> ");
              scanf(" %c", &rent);
              if(rent>='a' && rent<='z') rent -= 32;    // 소문자 -> 대문자
              if(rent == 'Y')
              {
                temp->rental = 'N';
                if(temp->rental = 'N') printf("대여처리 되었습니다.\n");
                else if(temp-> rental = 'Y') printf("대여처리를 실패하였습니다.\n");
              }
result++;
            }
            else if(temp -> rental = 'N')
            {
              printf("해당 도서는 현재 대여중인 상태입니다.");
            }
          }
          temp = temp->next;
        }
        if(result == 0)printf("검색하신 도서가 없습니다.\n");
        return;
      }
      else if(btn2 == 2)    // 저자명으로 검색
      {
        printf("검색하고 싶은 저자명 : ");
        scanf("%s",search);
        book* temp = h->head;
        while ( temp != NULL)
        {
          if(strcmp(search, temp-> author) == 0)
          {
            if(temp->rental = 'Y')
            {
              printf("대여하시겠습니까?(Y/N) >> ");
              scanf(" %c", &rent);
              if(rent>='a' && rent<='z') rent -= 32;    // 소문자 -> 대문자
              if(rent == 'Y')
              {
                temp->rental = 'N';
                if(temp->rental = 'N') printf("대여처리 되었습니다.\n");
                else if(temp-> rental = 'Y') printf("대여처리를 실패하였습니다.\n");
              }
              result++;
            }
            else if(temp -> rental = 'N')
            {
              printf("해당 도서는 현재 대여중인 상태입니다.");
            }
          }
          temp = temp->next;
        }
        if(result == 0)printf("검색하신 도서가 없습니다.\n");
        return;
      }
      else if(btn2 == 3)      // 출판사로 검색
      {
        printf("검색하고 싶은 출판사 : ");
        scanf("%s",search);
        book* temp = h->head;
        while ( temp != NULL)
        {
          if(strcmp(search, temp-> publisher) == 0)
          {
            if(temp->rental = 'Y')
            {
              printf("대여하시겠습니까?(Y/N) >> ");
              scanf(" %c", &rent);
              if(rent>='a' && rent<='z') rent -= 32;    // 소문자 -> 대문자
              if(rent == 'Y')
              {
                temp->rental = 'N';
                if(temp->rental = 'N') printf("대여처리 되었습니다.\n");
                else if(temp-> rental = 'Y') printf("대여처리를 실패하였습니다.\n");
              }
              result++;
            }
            else if(temp -> rental = 'N')
            {
              printf("해당 도서는 현재 대여중인 상태입니다.");
            }
          }
          temp = temp->next;
        }
        if(result == 0)printf("검색하신 도서가 없습니다.\n");
        return;
      }
      else if(btn2 == 4) return;    // 빠져나오기
      else printf("숫자를 잘못 입력하셨습니다. 다시 입력해주세요\n");
    }
  }
}

void deleteBook(headnode* h)
{
  int result = 0;
  int btn3;
  char btn4;
  int btn5;
  int del = 0; // 삭제하고 싶은 도서 번호
  printf("-----[ 도서 삭제 ]------\n");
  while(1){
    printf("1. 선택 삭제 2. 전체 삭제 3. 뒤로가기\n");
    printf("원하는 기능의 번호를 입력해주세요. >> ");
    scanf("%d",&btn3);
    if(btn3 == 1){      // 선택 삭제
      printf("삭제하고 싶은 도서 번호 : ");
      scanf("%d", &del);
      book*temp = h->head;
      if(del == 1)              // 첫번째 도서를 삭제하고자 할 때
      {
        if(temp->next == NULL)  // 애초에 도서가 1개만 등록되어 있는 경우
        {
          free(temp);
        }
        else                    // 도서가 2권 이상 등록되어 있는 경우
        {
          book*temp2 = temp->next;
          h->head = temp2;
          free(temp);
          result = 1;
          while (temp2 != NULL)
          {
            (temp2->booknum)--;
            temp2 = temp2 -> next;
          }
        }

      }
      else if(del>= 2)
      {
        while(temp->next != NULL)
        {
          book*temp2 = temp -> next;
          if(temp2->booknum == del)
          {
            if(temp2->next != NULL){
              temp -> next = temp2 -> next;
              free(temp2);
              temp2 = temp->next;
              while(temp2 != NULL){
                (temp2->booknum)--;
                temp2 = temp2 -> next;
              }
            }
            else if(temp2->next == NULL){
              free(temp2);
              temp->next = NULL;
              break;
            }
            bnum--;
            result = 1;
          }
          temp = temp->next;
        }
      }
      if(result == 1) printf("[ 삭제 완료 ]\n\n");
      else printf("[ 도서 번호가 잘못 입력되었습니다. ]\n\n");
    }
    else if(btn3 == 2){ //  전체 삭제(메모리 반납) 후 헤드노드 생성
      printf("정말 모든 도서를 삭제하시겠습니까?(Y/N) >>");
      scanf(" %c", &btn4);
      if(btn4 >= 'a' && btn4 <= 'z') btn4 -= 32;
      if(btn4 == 'Y'){
        book*temp = h -> head;
        if(temp->next == NULL) {
        free(temp);
        }
        else{
          while(temp != NULL)
          {
            h->head = temp->next;
            free(temp);
            temp = h->head;
          }
          free(h);
        }
        h = createHead();
        bnum = 0;
        printf("[ 모든 도서  삭제 완료 ]\n\n");
        return;
      }
      else if(btn4 == 'N'){
        printf("1. 도서관리 메뉴로 2. 삭제 처음으로\n");
        while(1){
          printf("원하는 기능의 번호를 입력해주세요 >> ");
          scanf("%d", &btn5);
          if(btn5 == 1) return;
          else if(btn5 == 2) break;
          else printf("숫자를 잘못 입력하셨습니다.\n");
        }
      }
    }
    else if(btn3 == 3) return;
    else printf("숫자를 잘못 입력하셨습니다. 다시 입력해주세요.\n");
  }
}

void returnBook(headnode* h)    // 도서 반납 함수
{
  printf("---[ 대출 도서 목록 ]---\n");
  book* temp = h->head;
  int result = 0;
  int btn6;

  while(temp != NULL)
  {
    if(temp -> rental == 'N')
    {
      printf("-----------------\n");
      printf("도서 번호 : %d\n", temp->booknum);
      printf("도서명 : %s\n", temp->title);
      printf("가격 : %d\n", temp->price);
      printf("저자 : %s\n", temp->author);
      printf("출판사 : %s\n", temp->publisher);
      printf("대여 가능 여부 : %c\n", temp->rental);
      result++;
    }
    temp = temp->next;
  }
  if(result == 0){
    printf("현재 대여 상태인 도서가 없습니다.\n");
    return;
  }
  else printf("-----------------\n\n");
  printf("1. 선택 도서 반납 2. 전체 도서 반납 3. 뒤로가기\n");

  while(1){
    printf("원하는 기능의 번호를 입력해주세요 >> ");
    scanf("%d",&btn6);
    while(getchar() != '\n');
    if(btn6 == 1){  // 선택 반납
      book*temp = h->head;
      int result = 0;
      char rent;
      int rnum;

      printf("반납처리 하고 싶은 도서 번호를 입력하시오: ");
      scanf("%d", &rnum);

      while (temp != NULL)
      {
        if(temp -> booknum == rnum)
        {
          temp->rental = 'Y';
          result = 1;
        }
        temp = temp -> next;
      }
      if(result == 1){
        printf("[ 반납 처리 완료 ]\n");
        return;
      }
      else printf("잘못된 도서 번호를 입력하였습니다.\n");
    }
    else if(btn6 == 2){ // 전체 반납
      book*temp = h->head;
      while(temp != NULL)
      {
        if(temp->rental == 'N') temp->rental = 'Y';
        temp = temp -> next;
      }
      printf("[ 모든 도서를 반납하였습니다. ]\n\n");
      break;
    }
    else if(btn6 == 3){ // 뒤로가기
      break;
    }
    else printf("잘못된 번호를 선택하였습니다.\n");
  }
}

void memoryDel(headnode* h) // 프로그램 종료시 메모리 반납용 함수
{
  book*temp = h -> head;
  if(temp == NULL) {
  free(temp);
  }
  else{
    while(temp != NULL)
    {
      h->head = temp->next;
      free(temp);
      temp = h->head;
    }
    free(h);
  }
}

