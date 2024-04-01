/* 헤더 파일 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct BOOK{
  int booknum;            // 도서 관리 번호
  char title[SIZE];       // 도서명
  int price;              // 가격
  char author[SIZE];      // 저자
  char publisher[SIZE];   // 출판사
  char rental;            // 대여 여부(Y/N)
  struct BOOK *next;      // 자기 참조 구조체
} book;

typedef struct HEAD{
  book* head;
} headnode;

typedef struct INFO{
  char id[30];
  char ps[30];
} info;

headnode* createHead();
void login();
void buyBook(headnode* h);
void showAllBook(headnode* h);
int searchBookTitle(headnode* h, char* sch);
int searchBookAuthor(headnode* h, char* sch);
int searchBookPublisher(headnode*h, char* sch);
int deleteBook(headnode* h, int del);
void deleteAll(headnode*h);
int showRentBook(headnode* h);
int returnBook(headnode* h);
void returnAll(headnode* h);
void memoryDel(headnode*h);
