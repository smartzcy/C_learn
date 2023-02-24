#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int num[1000];
    for(int i=0; i<n; i++){
        scanf("%d",&num[i]);
    }
    int k;
    int bool[1000];
    for(int i = 0;i < n;i++)bool[i] = 0;
    for(int i=0; i<n; i++){
        k = 0;
        for(int j = 1; j<n; j++){
            if(num[k] < num[j]  && bool[j] == 0 || bool[k] != 0){
                k = j;
            }
        }
        bool[k] = i + 1;
    }
    for(int i = 0; i < n; i++){
        if(i != n - 1){
            printf("%d ", bool[i]);
        }else{
            printf("%d\n",bool[i]);
        }
    }
}