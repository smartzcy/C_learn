#include<stdio.h>
int main(){
    int n;
    long long endtime;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld",&endtime);
        if ((endtime - 1) % 3 == 0)
        {
            printf("showshowshow\n");
        }else{
            printf("forever love\n");
        }
    }
}