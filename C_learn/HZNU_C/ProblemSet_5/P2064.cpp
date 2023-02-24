#include<iostream>
#include<stdio.h>
using namespace std;
int num[10010];
void ways(){
    num[1] = 1;
    num[2] = 1;
    for(int i = 3 ; i <= 10000;i++){
        num[i] = (num[i - 1] + num[i - 2] - 1) % 26 + 1;
    }
}
int main(){
    int n;
    ways();
    while(cin >> n){
        printf("%c\n",(num[n] - 1) % 26 + 97);
    }
}