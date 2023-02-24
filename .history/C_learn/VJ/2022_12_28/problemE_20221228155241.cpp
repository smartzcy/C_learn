#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        char mp[4050][4050];
        int p[4050][4050];
        int n;
        cin >> n;
        int cnt = 0;
        getchar();
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> mp[i][j];
                if (mp[i][j] == '1') cnt++;
                mp[i + n][j] = mp[i][j];
                mp[i][j + n] = mp[i][j];
                mp[i + n][j + n] = mp[i][j];
            }
            getchar();
        }
        for (int i = 1; i <= 2 * n; i++){
            for (int j = 1; j <= 2 * n; j++){
                p[i][j] = p[i - 1][j - 1] + (mp[i][j] == '1');
            }
        }
        int res = n * n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int num = p[i + n - 1][j + n - 1] - p[i - 1][j - 1];
                res = min(res, cnt - num + (n - num));
            }
        }
        cout << res << endl;
    }
}