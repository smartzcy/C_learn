#include<stdio.h>
int main(){
    int t,n;
    while (scanf("%d %d",&n,&t) != EOF){
        int id[6000];
        int direction[6000];
        int k = 0;
        for(int i = 0;i < n;i++){
            scanf("%d",&id[k++]);
            direction[i] = i;
        }
        for(int i = 0;i < t;i++){
            scanf("%d",&id[k++]);
            int toIp;
            scanf("%d",&toIp);
            int m = 0;
            for(int j = 0; j < k;j++){
                if(toIp == id[direction[j]]){
                    m = j;
                    break;
                }
            }
            for(int j = k; j > m;j--) direction[j] = direction[j - 1];
            direction[m] = k - 1;
        }
        for(int i = 0; i < k; i++){
            if(i == k - 1){
                printf("%d\n",id[direction[i]]);
            }else{
                printf("%d ",id[direction[i]]);
            }
        }
    }
}