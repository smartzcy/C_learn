#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;
int n , m;
int f[N];
string str;
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main(){
    cin >> n >> m;
    cin >> str;
    str = " " + str;
    for(int i = 1 ; i <= n ; i++) f[i] = i;
    for(int i = 1 , u , v ; i < n ; i++){
        cin >> u >> v;
        if(str[u] == str[v]){
            int uu = find(u);
            int vv = find(v);
            if(uu != vv) f[vv] = uu;
        }
    }
    for(int i = 1 , u , v ; i <= m ;i++){
        string s;
        cin >> u >> v >> s;
        int uu = find(u);
        int vv = find(v);
        if(uu == vv && str[uu] != s[0]) cout << "0";
        else cout << "1";
    }
}