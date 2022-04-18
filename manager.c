#include "manager.h"

void listProduct(Product *p[], int count){
    printf("\n No NAME DETAIL                       WEIGHT PRICE DEL\n");
    printf("======================================\n");
    for(int i=0; i<count; i++){
        if(p[i] == NULL) continue;
        printf("%2d ", i+1);
        readProduct(*p[i]);
    }
    printf("\n");
}      // 전체 등록된 제품 리스트 출력
