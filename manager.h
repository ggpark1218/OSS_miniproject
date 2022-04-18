#include "product.h"

void listProduct(Product *p[], int count);      // 전체 등록된 제품 리스트 출력
void searchProduct(Product *p[], int count);    // 제품이름 검색
void searchDetail(Product *p[], int count);     // 제품설명 검색
void searchPrice(Product *p[], int count);      // 가격 범위 검색
void saveData(Product *p[], int count);          // 파일로 저장
