#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , sum = 0 , A = 0 , D = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            A += D;
            int a , b , c;
            cin >> a >> b >> c;
            if(b * (n - i - 1) > a && b * (n - i - 1) > c) D += b;
            else if(a + A > b * (n - i - 1) && a + A > c || i == n) sum += a + A;
            else A += c;
        }
        cout << sum << endl;
    }
}