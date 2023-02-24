#include<iostream>
using namespace std;
int main(){
    long long n , m;
    while(cin >> n >> m){
        long long count = 0;
        long long num[5];
        for(int i = 1 ; i <= 5;i++){
            long long k = 5 - i % 5;
            if(m < 5) count += (m - k) >= 0 ? 1 : 0;
            else count += ((m - k) / 5 + 1);
            num[i - 1] = count;
        }
        cout << num[4] * (n / 5) + num[n % 5 - 1] << endl;
    }
    return 0;
}   