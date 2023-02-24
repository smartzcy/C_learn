#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        double A , B , H , a , b , h;
        cin >> A >> B >> H;
        cin >> a >> b >> h;
        if((A * B * H) / (A * B - a * b) <= h){
            H = (A * B * H) / (A * B - a * b);
        }else{
            H = (A * B * H + a * b * h) / (A * B);
        }
        printf("%.2f\n",H);
    }
}