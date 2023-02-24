#include<iostream>
using namespace std;
int count1(int n){
    int ans = 0;
    while(n != 0){
        ans += n % 2;
        n /= 2;
    }
    return ans;
}
int main(){
    int n , p , m , flag = 0;
    cin >> n >> p;
    for(int i = 1 ; i <= n ;i++){
        m = n - i * p;
        flag++;
        if(flag == 33) break;
        if(count1(m) == i){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}