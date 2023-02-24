#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long a1 , a2 , a3 , k;
        cin >> a1 >> a2 >> a3 >> k;
        if(a3 - a2 == a2 - a1) cout << (k - 1) * (a2 - a1) + a1 << endl;
        else{
            cout << a1 * pow(a3 / a2 , k - 1) << endl;
        }
    }
}