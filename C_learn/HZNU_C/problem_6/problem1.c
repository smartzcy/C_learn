#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; i++){
        int nums[10000];
        int n , k;
        scanf("%d",&n);
        scanf("%d",&k);
        for (int j=0; j<n; j++){
            scanf("%d",&nums[j]);
        }
        for(int j=0; j<n;j++){
            if(nums[j] == k){
                printf("%d\n",j + 1);
                break;
            }
        }
    }
}