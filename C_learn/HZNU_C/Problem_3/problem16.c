#include<stdio.h>
int main(){
    for(int i=1; i<10; i++){
        for(int j=1; j<=i; j++){
            if (j == i)
            {
                printf("%d*%d=%d\n", i, j,i*j);
            }else {
                printf("%d*%d=%d ", i, j, i*j);
            }
        }
    }
}