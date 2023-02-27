#include<iostream>
using namespace std;
int main(){
    double a;
    cin >> a;
    int k = 0;
    double num = 2;
    while(a > 0){
        a -= num;
        num *= 0.98;
        k++;
    }
    cout << k;
}