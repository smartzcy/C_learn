#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , num[200000];
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> num[i];
        }
        sort(num , num + n);
        if(n == 1 && num[0] > 1) cout << "NO" << endl;
        else if(num[n - 1] - num[n - 2] > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}