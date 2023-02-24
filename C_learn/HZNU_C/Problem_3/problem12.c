#include<stdio.h>
int main(){
    int num[3];
    scanf("%d",&num[0]);
    scanf("%d",&num[1]);
    scanf("%d",&num[2]);
    int max = num[0];
    int min = num[0];
    int number = num[1] + num[2] + num[0];
    for(int i=1; i<3; i++){
        if (max < num[i])
        {
            max = num[i];
        }
        if (min > num[i])
        {
            min = num[i];
        }
    }
    printf("%d %d %d",min,number-min-max,max,max);
}