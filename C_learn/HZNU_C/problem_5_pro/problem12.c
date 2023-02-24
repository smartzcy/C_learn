#include<stdio.h>
#include<math.h>
int main(){
    int N;
    while (scanf("%d", &N) != EOF)
    {
        int nums[10000];
        for (int i = 0; i < N; i++)scanf("%d", &nums[i]);
        for(int i = 0; i < N; i++){
            for (int j = N - 1; j > i; j--){
                if(abs(nums[j]) < abs(nums[j - 1])){
                    int k = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = k;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(i != N - 1){
                printf("%d ", nums[i]);
            }else{
                printf("%d\n", nums[i]);
            }
        }
        printf("\n");
    }
}