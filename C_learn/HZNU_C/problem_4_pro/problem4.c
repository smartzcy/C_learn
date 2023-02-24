#include<stdio.h>
int jos(int n);
int main()
{
    int n,s,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s = jos(n);
        printf("%d ", s);
    }
    return 0;
}
int jos(int n){
    int nums[1000];
    int flag = 0;
    int i;
    int count = 1;
    for(i=0; i<n; i++){
        nums[i] = 0;
    }
    i = 0;
    while (1)
    {
        if(flag == n - 1) break;
        if(nums[i] == 1) i++;
        else{
            if(count == 7){
                nums[i] = 1;
                flag++;
                count = 1;
                i++;
            }else{
                count++;
                i++;
            }
        }
        if(i == n) i = 0;
    }
    for(i=0; i< n;i++){
        if(nums[i] != 1){
            return i + 1;
        }
    }
}