#include "product.h"

int selectMenu(){
    int menu;
    printf("\n*** shoping shop ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createProduct(Product *p){
    printf("제품명은? ");
    scanf(" %[^\n]s", p->product_name);

    printf("설명은? ");
    scanf(" %[^\n]s", p->detail);

    printf("중량은? ");
    scanf(" %s", p->weight);

    printf("판매가격은? ");
    scanf("%d", &p->price);

    printf("배송방법은? (1:새벽배송 /2:택배배송) ");
    scanf("%d", &p->delivery);
    printf("=> 추가됨!\n");

    return 1;
}                // 제품을 추가하는 함수
void readProduct(Product p){
    printf("%4s %10s %5s %6d원 %2d\n", p.product_name, p.detail, p.weight, p.price, p.delivery);
}                    // 하나의 제품 출력 함수
int updateProduct(Product *p){
    printf("수정할 제품명은? ");
    scanf(" %[^\n]s", p->product_name);

    printf("수정할 설명은? ");
    scanf(" %[^\n]s", p->detail);

    printf("수정할 중량은? ");
    scanf(" %s", p->weight);

    printf("수정할 판매가격은? ");
    scanf("%d", &p->price);

    printf("수정할 배송방법은? (1:새벽배송 /2:택배배송) ");
    scanf("%d", &p->delivery);
    printf("=> 수정성공!\n");

    return 1;
}                  // 이미 추가된 제품을 수정하는 함수
int deleteProduct(Product *p[], int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소:0)? ");
    scanf("%d", &no);
    return no;
}     // 제품 삭제를 하기 위한 함수
