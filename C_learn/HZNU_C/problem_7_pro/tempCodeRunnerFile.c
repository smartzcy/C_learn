#include<stdio.h>
#include<math.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int t;
        scanf("%d",&t);
        for(int i = 0; i < t; i++) {
            int n;
            scanf("%d",&n);
            if( i != t - 1)printf("%d ",(int)pow(2,(int)(log(n) / log(2))));
            else printf("%d\n",(int)pow(2,(int)(log(n)/log(2))));
        }
    }
}