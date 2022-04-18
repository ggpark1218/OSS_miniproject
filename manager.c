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
                readProduct(*p[i]);
		scnt++;
            }
    }

    if(scnt == 0) {
        printf("=>검색된 데이터 없음!");
    }
    printf("\n");

}	//제품 이름 검색

void searchDetail(Product *p[], int count){
    int scnt = 0;
    char search[20];

    printf("상세 설명이 필요한 제품의 이름은? ");
    scanf(" %s", search);

    printf("*****************\n");

    for(int i=0; i<count; i++){
       if(p[i]->price == -1) continue;
            if(strstr(p[i]->product_name, search)){
                printf("%2d ", i+1);
                printf(" product_name: %s \n detail: %s", p[i]->product_name, p[i]->detail);
                scnt++;
            }
    }

    if(scnt == 0) {
        printf("=>검색된 데이터 없음!");
    }
    printf("\n");

} //제품 상세 설명 검색

void searchPrice(Product *p[], int count){
	int scnt = 0;
	int min=0, max=0;
	printf("검색할 최소가격과 최대 가격은?\n");
	printf("최소가격: ");
	scanf("%d", &min);
	printf("최대가격: ");
	scanf("%d", &max);
	printf("\n No NAME DETAIL        WEIGHT PRICE DEL\n");
    printf("======================================\n");
	for(int i =0; i<count; i++){
		if(p[i]->price >= min && p[i]->price <= max){
			printf("%2d", i+1);
			readProduct(*p[i]);
			printf("\n");
			scnt++;
		}
	}
	if(scnt == 0){
		printf("검색된 데이터 없음!\n");
	}
} //제품 가격 범위 검색

void saveData(Product *p[], int count){
    FILE *fp;
     fp = fopen("product.txt", "wt");
     for(int i=0; i<count; i++){
                if(p[i] == NULL) continue;
                fprintf(fp,"%s %s %s %d원 %d\n", p[i]->product_name, p[i]->detail, p[i]->weight, p[i]->price, p[i]->delivery);
        }
        fclose(fp);
        printf("저장됨!\n");
}//파일로 저장

int loadData(Product *p[]){
        int count = 0;
        FILE *fp;
        fp = fopen("product.txt", "wt");
        if(fp == NULL){
                printf("=> 파일 없음\n");
                return 0;
        }
        for(int i=0; i<count; i++){
                fscanf(fp,"%[^\n]s %[^\n]s %s %d %d", p[i]->product_name, p[i]->detail, p[i]->weight, &p[i]->price, &p[i]->delivery);
                if(feof(fp)){
                        break;
                }
        }
        fclose(fp);
        printf("=>로딩 성공\n");
        return count;
}  // 전체 등록된 제품 리스트 출력
