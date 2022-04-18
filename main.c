#include "product.h"
#include "manager.h"

int main(void){
#ifdef DEBUG
    printf("Debug: [%s : %d] %s\n",__FILE__,__LINE__,__func__);
#endif
    int count = 0, menu;
    Product *fp[100];
    int index =0;

    count = loadData(fp);
    index = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 || menu == 4){
             if (count == 0) 
                continue;
        }
        if (menu == 1){
            if(count >0){
                listProduct(fp, index);
	    }else{
                printf("데이터가 없습니다.\n");
	    }
#ifdef DEBUG
	printf("\nDebug:[%s : %d] %s %s %s",__FILE__,__LINE__,__func__,__DATE__,__TIME__);
	printf("\nDebug: [listProduct called] count = %d, index = %d\n", count, index);
#endif
        }
        else if (menu == 2){
            fp[index] = (Product *)malloc(sizeof(Product));
            count += createProduct(fp[index++]);
#ifdef DEBUG
	printf("\nDebug:[%s : %d] %s %s %s",__FILE__,__LINE__,__func__,__DATE__,__TIME__);
	printf("\nDebug: [listProduct called] count = %d, index = %d\n", count, index);
#endif
        }
        else if (menu == 3){
            int no = deleteProduct(fp, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(fp[no-1]);
        }
        else if (menu == 4){
            int no = deleteProduct(fp, index);
             int deleteok;
             printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(fp[no-1])
                    free(fp[no-1]);
                fp[no-1] = NULL;
                count --;
                printf("=> 삭제됨!\n");
            }
#ifdef DEBUG
	printf("\nDebug:[%s : %d] %s %s %s",__FILE__,__LINE__,__func__,__DATE__,__TIME__);
	printf("\nDebug: [listProduct called] count = %d, index = %d\n", count, index);
#endif 
        }
	else if (menu == 5){
			if(count ==0){
				printf("데이터가 없습니다!\n");
			}
			else{
				saveData(fp, index);
			}
		}
	else if (menu == 6){
			int searchMenu;
			printf("어떤 것을 검색 하시겠습니까?\n1.제품명 검색\n2.상세설명 검색\n3.가격 검색\n\n");
			printf("번호를 고르세요");
			scanf("%d", &searchMenu);
			switch(searchMenu){
				case 1 : searchProduct(fp, index); break;
				case 2 : searchDetail(fp, index); break;
				case 3 : searchPrice(fp, index); break;
				default: break;
			}
		}
    }
    printf("종료됨!\n");
    return 0;
}


