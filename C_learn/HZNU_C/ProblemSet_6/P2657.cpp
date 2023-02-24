#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , num[100001];
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> num[i];
    }
    sort(num,num + n);
    int max = num[n - 1];
    for(int i = n - 1;i >= 1;i--){
        for(int j = i - 1; j >= 0;j--){
            if(num[i] % num[j] != 0){
                if(max < num[i] + num[j]) max = num[i] + num[j];
            }
            if(num[i] + num[j] <= max) break;
        }
        if(2 * num[i] <= max) break;
    }
    cout << max;
}