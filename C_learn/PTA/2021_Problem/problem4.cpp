#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int m = n;
        while(m > 0){
            if(m % 10 == 0) break;
            m /= 10;
        }
        if(m != 0 || n == 0) cout << "AC" << endl;
        else if(n % 54 == 0 && (n % 7 != 0 && n % 8 != 0)) cout << "AC" << endl;
        else if((n % 7 == 0 || n % 8 == 0) && (n % 6 != 0 && n % 9 != 0)) cout << "WA" << endl;
        else cout << "TLE" << endl;
    }
}