#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        double a = 1.0;
        for(int i = 0 ; i < n;i++){
            a *= 3.0/2;
            if(a > 2.0) a /= 2.0;
        }
        printf("%.5f\n",a);
    }
}