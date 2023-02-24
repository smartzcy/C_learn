#include<iostream>
using namespace std;
int main(){
    string a , b;
    int x , y;
    cin >> a >> x >> b >> y;
    int num1 = 0, num2 = 0;
    for(int i = 0 ;i < a.length();i++){
        if(a[i] - '0' == x) num1 = num1 * 10 + x;
    }
    for(int i = 0 ; i < b.length();i++){
        if(b[i] - '0' == y) num2 = num2 * 10 + y;
    }
    cout << num1 + num2;
}