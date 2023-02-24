// #include<iostream>
// #include<set>
// using namespace std;
// set<pair<int,int> > s;
// int n , k;
// void way(int a , int b){
//     s.insert({a , b});
//     s.insert({a + 1 , b});
//     s.insert({a + 1 , b + 1});
//     if(a + 1 == n) return ;
//     way(a + 1 , b);
//     way(a + 1 , b + 1);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> k;
//     for(int i = 0 ; i < k;i++){
//         int a , b;
//         cin >> a >> b;
//         way(a , b);
//         if(s.find({a , b - 1}) != s.end()){
//             s.insert({a - 1 , b - 1});
//         }else if(s.find({a , b + 1}) != s.end()){
//             s.insert({a - 1 , b});
//         }
//     }
//     cout << s.size();
// }

#include <iostream> #include <vector> using namespace std; const int MAXN = 1005; int n, m; vector<int> leaves[MAXN]; bool is_black[MAXN][MAXN]; int main() { cin >> n >> m; for (int i = 0; i < m; i++) { int x, y; cin >> x >> y; leaves[x].push_back(y); is_black[x][y] = true; } for (int i = n; i >= 1; i--) { for (int j = 0; j < leaves[i].size(); j++) { if (is_black[i][leaves[i][j]]) { is_black[i + 1][leaves[i][j]] = true; is_black[i + 1][leaves[i][j] + 1] = true; } } } int ans = 0; for (int i = 1; i <= n; i++) { for (int j = 0; j < leaves[i].size(); j++) { if (is_black[i][leaves[i][j]] && is_black[i + 1][leaves[i][j]] && is_black[i + 1][leaves[i][j] + 1]) { is_black[i][leaves[i][j]] = true; } } } for (int i = 1; i <= n; i++) { for (int j = 0; j < leaves[i].size(); j++) { if (is_black[i][leaves[i][j]]) { ans++; } } } cout << ans << endl; return 0; }