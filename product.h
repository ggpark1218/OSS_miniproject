#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char product_name[20];  //제품명
    char detail[100];       //설명
    char weight[20];        //중량
    int price;              //판매가격
    int delivery;           //배송방법
} Product;
 

int createProduct(Product *p);                  // 제품을 추가하는 함수
void readProduct(Product p);                    // 하나의 제품 출력 함수
int updateProduct(Product *p);                  // 이미 추가된 제품을 수정하는 함수
int deleteProduct(Product *p[], int count);     // 제품 삭제를 하기 위한 함수

void searchProduct(Product *p[], int count);    // 제품이름 검색
void searchDetail(Product *p[], int count);     // 제품설명 검색
void searchPrice(Product *p[], int count);      // 가격 범위 검색

void saveData(Product *p[], int count);         // 파일로 저장
int loadData(Product *p[]);                     // 파일 불러오기

void listProduct(Product *p[], int count);      // 전체 등록된 제품 리스트 출력
int selectMenu();   //메뉴 선택
