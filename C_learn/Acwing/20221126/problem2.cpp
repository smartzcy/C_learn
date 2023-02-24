#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n <= 5) cout << (char)('a' - 1 + n);
    else{
        int k = 1;
        while((2 * k - 1) * 5 < n){
            k *= 2;
        }
        n -= (2 * (k / 2) - 1) * 5;
        cout << (char)('a' + (n - 1) / k);
    }
}