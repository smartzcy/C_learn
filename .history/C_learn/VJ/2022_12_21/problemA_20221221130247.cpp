#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , x;
        cin >> n >> x;
        cout << (n - 2) / x + 1 << endl;
    }
}