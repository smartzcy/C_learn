#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        vector<int> er(64,0);
        long long n , m , num , sum = 0;
        cin >> n >> m;
        for(int i = 0 ; i < m;i++){
            cin >> num;
            sum += num;
            er[__lg(num)]++;
        }
        if(sum < n){
            cout << "-1";
            continue;
        }
        int ans = 0;
        for(int i = 0 ; i <= 63;i++){
            if(n % 2 == 1){
                int j = i;
                while(er[j] == 0) j++;
                while(j != i){
                    er[j]--;
                    er[j - 1] += 2;
                    ans++;
                    j--;
                }
            }
            n /= 2;
            er[i + 1] += er[i] / 2;
        }
        cout << ans << endl;
    }
}