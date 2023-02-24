#include<stdio.h>
#include<string.h>
#include<math.h>
int isPrime[1000011];
void getprime(){
    for(int i=2; i<1000011; i++){
        int j;
        int k = (int)sqrt((double)i);
        for (j = 2; j <= k; j++){
            if (i % j == 0){
                break;
            }
        }
        if(j > k){
            isPrime[i] = 1;
        }else{
            isPrime[i] = 0;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    getprime();
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(isPrime[n])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
} 