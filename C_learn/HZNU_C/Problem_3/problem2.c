#include<stdio.h>
int main(){
    int n1;
    while(scanf("%d",&n1)!=EOF){
        int n2,n3,n4,m,ak,p;
        float money;
        scanf("%d",&n2);
        scanf("%d",&n3);
        scanf("%d",&n4);
        scanf("%d",&m);
        scanf("%d",&ak);
        scanf("%d",&p);
        if(n1 != 0){
            money = money + (float)m / n1;
        }
        if(n2 != 0){
            money = money + (float)m / n2;
        }
        if(n3 != 0){
            money = money + (float)m / n3;
        }
        if(n4 != 0){
            money = money + (float)m / n4;
        }
        money = money + 5 * ak;
        if(p == 1){
            money = money + 5;
        }else if (p == 2){
            money = money + 3;
        }else if(p == 3){
            money = money + 1;
        }
        printf("%.2f\n", money);
        money = 0;
    }
}