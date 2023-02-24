#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    double num;
    for(int i = 1 ; i <= n;i++){
        cin >> num;
        sum += (long long)(num * 1000) * i * (n - i + 1);
    }
    printf("%.2f",1.0 * sum / 1000);
}