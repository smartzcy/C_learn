#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a1 = 0 , a2 = 0 , a3 = 0 , a4 = 0 , a5 = 0;
    int k = 1 , m = 0;
    int flag = 0;
    while(n--){
        int num;
        cin >> num;
        if(num % 10 == 0) a1 += num;
        if(num % 5 == 1){
            a2 += num * k;
            k = -k;
            flag++;
        }
        if(num % 5 == 2) a3++;
        if(num % 5 == 3) {
            a4 += num;
            m++;
        }
        if(num % 5 == 4) a5 = a5 > num ? a5 : num;
    }
    if(a1 != 0) cout << a1;
    else cout << "N";
    if(flag != 0) cout << " " << a2;
    else cout << " " << "N";
    if(a3 != 0) cout << " " << a3;
    else cout << " " << "N";
    if(a4 != 0) printf(" %.1f",(double)a4 / m);
    else cout << " " << "N";
    if(a5 != 0) cout << " " << a5;
    else cout << " " << "N";
}