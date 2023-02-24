#include <iostream>
#include<stdio.h>
using namespace std;
int num[10][10];
int main(){
    int n , k = 1 , x = 1 , y = 0;
    cin >> n;
    while(k <= n * n){
        while(y < n && !num[x][y + 1]) num[x][++y] = k++;
        while(x < n && !num[x + 1][y]) num[++x][y] = k++;
        while(y > 1 && !num[x][y - 1]) num[x][--y] = k++;
        while(x > 1 && !num[x - 1][y]) num[--x][y] = k++;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            printf("%3d", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}