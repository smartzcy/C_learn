#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
    double x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x , y;
    double num[2100];
    int k = 0;
    while (cin >> x >> y){
        num[k] = x;
        num[k + 1] = y;
        k += 2;
    }
    int i , n = 0;
    for(i = 0 ; i <= k - 2;i+=2){
        double direction1 = sqrt((num[i] - x1) * (num[i] - x1) + (num[i + 1] - y1) * (num[i + 1] - y1));
        double direction2 = sqrt((num[i] - x2) * (num[i] - x2) + (num[i + 1] - y2) * (num[i + 1] - y2));
        if(direction1 * 2 <= direction2){
            printf("The gopher can escape through the hole at (%.3f,%.3f).",num[i],num[i + 1]);
            n = 1;
            break;
        }
    }
    if(n == 0){
        printf("The gopher cannot escape.");
    }
}