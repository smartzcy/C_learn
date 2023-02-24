#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int m = sqrt(n);
        if(m * m == n){
            cout << 2 * (m - 1) << endl;
        }else if(m * (m + 1) >= n){
            cout << 2 * m - 1 << endl;
        }else{
            cout << 2 * m << endl;
        }
    }
}
// 42 21 14 7(5 + 6) 6(6 + 5) 3(13 + 2)   6
// 5 2 2 1
// 7 3 3 1 (2 + 2)