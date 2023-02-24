#include<stdio.h>
int main(){
    int num[10];
    int f[10];
    for(int i=0; i<10; i++){
        scanf("%d",&num[i]);
        f[i] = 1;
    }
    for(int i=0; i<10; i++){
        for(int j = 0; j<i; j++)
            if(num[j] < num[i]) f[i] = (f[i] > f[j] + 1? f[i]:f[j] + 1);
    }
    int x = 1;
    for(int i=0; i<10; i++)
        x = (x > f[i]? x : f[i]);
    printf("%d", x);
}