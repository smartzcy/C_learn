#include<iostream>
using namespace std;
int main(){
    const double pi = 3.14;
    double a , b;
    cin >> a >> b;
    double mj , xygg , hxgg , Lily;
    cin >> mj >> xygg >> hxgg >> Lily;
    double s = (a / 2 - b) * (a / 2 - b) * pi;
    int count = 0;
    if(s < mj){
        if(count == 0) cout << "mj";
        else cout << " " << "mj";
        count++;
    }
    if(s < xygg){
        if(count == 0) cout << "xygg";
        else cout << " " << "xygg";
        count++;
    }
    if(s < hxgg){
        if(count == 0) cout << "hxgg";
        else cout << " " << "hxgg";
        count++;
    }
    if(s < Lily){
        if(count == 0) cout << "Lily";
        else cout << " " << "Lily";
        count++;
    }
    if(count == 0) cout << "None";
}