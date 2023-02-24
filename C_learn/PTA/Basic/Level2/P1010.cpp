#include<iostream>
using namespace std;
int main(){
    int n , m;
    int k = 0;
    while (cin >> n >> m){
        if(m != 0){
            if(k == 0){
                k = 1;
                cout << n * m;
            }else cout << " " << n * m;
            cout << " " << --m;  
        }
    }
    if(k == 0) cout << "0 0";
}