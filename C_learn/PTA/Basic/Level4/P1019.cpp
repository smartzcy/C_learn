#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num[4] = {0};
    for(int i = 0 ;i < 4;i++){
        num[i] = n % 10;
        n /= 10;
    }
    sort(num,num + 4);
    int min = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
    int max = num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
    printf("%04d - %04d = %04d\n",max , min , max - min);
    n = max - min;
    while(n != 6174 && n != 0){
        for(int i = 0 ;i < 4;i++){
            num[i] = n % 10;
            n /= 10;
        }
        sort(num,num + 4);
        int min = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
        int max = num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
        printf("%04d - %04d = %04d\n",max , min , max - min);
        n = max - min;
    }
}