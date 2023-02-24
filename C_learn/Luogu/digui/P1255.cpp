#include<iostream>
using namespace std;
long long num[5001];
void way(){
    num[1] = 1;
    num[2] = 2;
    for(int i = 3 ; i <= 5000 ; i++){
        num[i] = num[i - 1] + num[i - 2];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    way();
    long long n;
    cin >> n;
    cout << num[n] << endl;
}