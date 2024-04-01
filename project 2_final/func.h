#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

/* 헤 더 파 일 */

typedef struct BOOK{
  int booknum;            // 도서 관리 번호
  char title[SIZE];       // 도서명
  int price;              // 가격
  char author[SIZE];      // 저자
  char publisher[SIZE];   // 출판사
  char rental;            // 대여 여부(Y/N)
  struct BOOK *next;      // 자기 참조 구조체
} book;

//int bnum = 0; // 도서 관리 번호에서 사용할 전역변수

typedef struct HEAD{
  book* head;
} headnode;

typedef struct INFO{
  char id[30];
  char ps[30];
} info;

headnode* createHead();
void login();
int showMenu();
void buyBook(headnode* h);
void showAllBook(headnode* h);
void searchBook(headnode* h);
void deleteBook(headnode* h);
void returnBook(headnode* h);
void memoryDel(headnode*h);
