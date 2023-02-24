#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n < 15) {
            cout << "-1";
            continue;
        }
        cout << n - 7 << endl;
    }
}