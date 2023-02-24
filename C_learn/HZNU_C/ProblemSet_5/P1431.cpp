#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    double money;
    while (cin >> money){
        int m = money * 10;
        int k = 0;
        int num = 0;
        int n = 1;
        while (m != 0){
            if(m % 10 == 6){
                k = 1;
                num = num + n * 9;
            }
            else if(m % 10 == 2){
                k = 1;
                num = num + n * 5;
            }else{
                num = num + n * (m % 10);
            }
            n *= 10;
            m /= 10;
        }
        if(k == 1) printf("%.1f\n",num / 10.0);
        else printf("The price cannot be raised.\n");
    }
    
    
}