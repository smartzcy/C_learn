#include<iostream>
#include<stdio.h>
#define pi 3.1415926535
using namespace std;
void pri(){
    cout << "1-Ball" << endl;
    cout << "2-Cylinder" << endl;
    cout << "3-Cone" << endl;
    cout << "other-Exit" << endl;
    cout << "Please enter your command:" << endl;
}
int main(){
    int n;
    pri();
    while(cin >> n){
        if(n == 1){
            cout << "Please enter the radius:" << endl;
            double a;
            cin >> a;
            printf("%.2f\n",4 / 3.0 * pi * a * a * a);
        }else if(n == 2) {
            cout << "Please enter the radius and the height:" << endl;
            double r , h;
            cin >> r >> h;
            printf("%.2f\n" , pi * r * r * h);
        }else if(n == 3) {
            cout << "Please enter the radius and the height:" << endl;
            double r , h;
            cin >> r >> h;
            printf("%.2f\n" , 1 / 3.0 * pi * r * r * h);
        }else{
            break;
        }
        pri();
    }
}