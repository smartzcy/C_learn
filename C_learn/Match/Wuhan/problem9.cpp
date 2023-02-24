#include<iostream>
#include<algorithm>
using namespace std;
long long num[200001];
long long gcd_2(long long a, long long b){
    return a == b ? a:gcd_2(a>b ? a-b:a, b>a ? b-a:b);
}
int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> num[i];
    }
    int flag = 0;
    for(int i = n - 1 ; i >= 1 && flag == 0 ; i--){
        long long min1 = num[i] , gcd = num[i + 1];
        for(int j = i - 1 ; j >= 1 ; j--){
            min1 = min(min1 , num[j]);
            gcd = gcd_2(gcd , num[j]);
            if(min1 < gcd){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1) cout << "Rude" << endl;
    else cout << "Elegant" << endl;
}