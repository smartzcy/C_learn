#include<stdio.h>
#include<string.h>
int main(){
    char N[11];
    char M[11];
    while (~scanf("%s %s",N,M))
    {
        getchar();
        for(int i = 0; i <= strlen(N) - strlen(M);i++){
            if(N[i] == M[0]){
                int j;
                for(j = 1; j < strlen(M);j++){
                    if(M[j] != N[i + j]){
                        break;
                    }
                }
                if(j == strlen(M)){
                    printf("%d\n",i);
                    break;
                }
            }
            if(i == strlen(N) - strlen(M)) printf("-1\n");
        }
    }
    return 0;
}