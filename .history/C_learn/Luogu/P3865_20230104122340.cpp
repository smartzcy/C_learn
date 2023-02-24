#include<iostream>
#include<algorithm>
using namespace std;
int st[100001][22];
int N , M;
void ST(){
    for(int i = 1 ; i < 22;i++)
        for(int j = 1 ; j + (1 << i) - 1 <= N;j++)
            st[j][i] = max(st[j][i - 1] , st[j + (1 << (i - 1))][i - 1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1 ; i <= N;i++) {
        cin >> st[i][0];
    }

}