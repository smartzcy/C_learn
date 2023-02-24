#include<stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    int num[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            num[i][j] = 48;
        }
    }
    for(int i=0; i<N; i++){
        int x , y;
        char z;
        scanf("%d %d %c", &x, &y, &z);
        num[x][y] = z;
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(j == 3){
                printf("%c\n", num[i][j]);
            }else{
                printf("%c ", num[i][j]);
            }
        }
    }
}