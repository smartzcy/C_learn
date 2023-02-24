#include<iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        long long n , m , sum = 0;
        cin >> n >> m;
        for(int j = 1 ; j <= n / m ;j++){
            sum += (m % 10 * j) % 10;
        }
        cout << sum << endl;
    }
}