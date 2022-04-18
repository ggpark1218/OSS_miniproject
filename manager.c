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

void searchProduct(Product *p[], int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름은? ");
    scanf(" %s", search);

    printf("*****************\n");

    for(int i=0; i<count; i++){
       if(p[i]->price == -1) continue;
            if(strstr(p[i]->product_name, search)){
                printf("%2d ", i+1);
                readScore(p[i]);
                scnt++;
            }
    }

    if(scnt == 0) {
        printf("=>검색된 데이터 없음!");
    }
    printf("\n");

}	//제품 이름 검색
