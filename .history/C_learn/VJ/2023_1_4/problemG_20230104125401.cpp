#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int st[100001][22];
int N, M;
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
void ST(){
    for (int i = 1; i <= __lg(N); i++)
        for (int j = 1; j + (1 << i) - 1 <= N; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    N = read();
    M = read();
    for (int i = 1; i <= N; i++) st[i][0] = read();
    ST();
    for (int i = 0; i < M; i++){
        int l = read(), r = read();
        int k = __lg(r - l + 1);
        cout << max(st[l][k], st[r - (1 << k) + 1][k]) << "\n";
    }
    return 0;
}