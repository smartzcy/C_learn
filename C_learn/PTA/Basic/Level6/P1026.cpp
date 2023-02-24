#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a , b;
    cin >> a >> b;
    int num = (b - a) / 100 + ((b - a) % 100 >= 50 ? 1 : 0);
    printf("%02d:%02d:%02d\n",num / 3600 , num % 3600 / 60 , num % 60);
}