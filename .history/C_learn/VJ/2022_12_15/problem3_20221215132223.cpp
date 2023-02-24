#include<iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        long long sum = 0;
        long long n , m;
        cin >> n >> m;
        for(long long j = m ; j <= n ; j += m){
            sum += j % 10;
        }
        cout << sum << endl;
    }
}