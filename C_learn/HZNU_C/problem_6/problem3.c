#include<stdio.h>
int main(){
    int T;
    int nums[100][100];
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        int num = 0;
        int n,k;
        scanf("%d",&n);
        scanf("%d",&k);
        for(int j=0; j<n; j++){
            for(int j1=0; j1<n; j1++) {
                scanf("%d",&nums[j][j1]);
            }
        }
        for(int j=0; j<n;j++){
            for(int j1 = 0;j1 < j;j1++){
                if(nums[j][j1] > k) num++;
            }
        }
        printf("%d\n",num);
    }
}