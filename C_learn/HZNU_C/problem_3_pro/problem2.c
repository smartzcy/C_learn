#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        int year,weekday;
        scanf("%d",&year);
        int nums[] =  {7,1,2,3,4,5,6};
        weekday = (12 + 3 * 6 / 5 + year + year / 4 - year / 100 + year / 400) % 7;
        if(nums[weekday] == 1){
            printf("%d\n",9);
        }else if(nums[weekday] == 2 || nums[weekday] == 7){
            printf("%d\n",6);
        }else{
            printf("%d\n",5);
        }
    }
}