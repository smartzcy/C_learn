#include<stdio.h>
int main(){
    int T;
    int black[] = {5,4,8,7,12,10};
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        int L , K;
        int x[5];
        scanf("%d",&L);
        scanf("%d",&K);
        for(int j=0; j<5; j++){
            scanf("%d",&x[j]);
        }
        if (L < 6){
            printf("none\n");
        }else {
            int power = black[(L - 1) / 5 * 2 - K -1 ] * 300;
            int dead = 0;
            for(int j=0; j<5; j++) {
                if (x[j] > power){
                    break;
                }else {
                    power = power - 300 * (x[j] / 300);
                    if(x[j] % 300 > 0){
                        power = power - 300;
                    }
                    dead++;
                }
            }
            if(dead == 0){
                printf("none\n");
            }else if (dead == 1){
                printf("first blood\n");
            }else if (dead == 2){
                printf("double kill\n");
            }else if (dead == 3){
                printf("triple kill\n");
            }else if (dead == 4){
                printf("ultra kill\n");
            }else if (dead == 5){
                printf("rampage\n");
            }
            printf("\n");
        }
    }
}