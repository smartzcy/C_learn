#include<iostream>
using namespace std;
long long count1(long long n){
    long long ans = 0;
    while(n != 0){
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
int main(){
    long long n , p , m , flag = 0;
    cin >> n >> p;
    for(int i = 1 ; i <= 64 ;i++){
        m = n - i * p;
        if(count1(m) == i){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}