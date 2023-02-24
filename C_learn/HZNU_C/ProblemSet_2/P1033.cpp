#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int N;
    while (scanf("%d",&N) != EOF){
        int num[8] = {1,2,3,4,5,6,7,8};
        do{
            for(int i = 0;i < N;i++){
                printf("%d",num[i]);
            }
            printf("\n");
        }while (next_permutation(num , num + N));
        int num1[] = {8,7,6,5,4,3,2,1};
        do{
            for(int i = 8 - N;i < 8;i++){
                printf("%d",num1[i]);
            }
            printf("\n");
        }while (prev_permutation(num1 + 8 - N , num1 + 8));
        printf("\n");
    }
    return 0;
}