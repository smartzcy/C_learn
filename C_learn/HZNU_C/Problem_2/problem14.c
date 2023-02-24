#include<stdio.h>
int main(){
    int N;
    while (scanf("%d", &N) != EOF)
    {
        if (N % 1024 == 0 || N == 1)
        {
            printf("YES\n");
        }else {
            while (N > 0)
            {
                if(N % 2 != 0){
                    printf("NO\n");
                    break;
                }else if (N == 2){
                    printf("YES\n");
                    break;
                }
                N /= 2;
            }
        }
    }
}