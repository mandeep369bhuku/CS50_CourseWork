#include<cs50.h>
#include<stdio.h>

int main(void){
    int ht;
    do{
        ht = get_int("Height: ");
    }while (ht<1);

    for (int i=0; i<ht;i++){
        for (int j=0; j<2*ht+2; j++){
            if(j>=ht-1-i && j<ht){
                printf("#");
            }
            else if (j>ht+1 && j<ht+3+i){
                printf("#");
            }

            else if (j>ht+2+i){
                break;
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
