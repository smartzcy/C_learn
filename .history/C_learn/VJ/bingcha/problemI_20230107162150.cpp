#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int n;
unordered_map<int , int> map1 , f;
pair<int , int> q[100050];
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void INIT(){
    for(int i = 1 ; i <= n ; i++)
        f[i] = i;
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        map1.clear();
        int cnt = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; i++){
            cin >> q[i].first >> q[i].second;
            f[q[i].first] = q[i].first;
            f[q[i].second] = q[i].second;
        }
        for(int i = 1 ; i <= n ; i++){
            int a , b;
            a = q[i].first;
            b = q[i].second;
            if(find(a) != find(b)) f[find(b)] = f[find(a)];
        }
        for(int i = 1 ; i <= n ;i++){
            map1[find(q[i].first)]++;
            cnt = max(cnt , map1[find(q[i].first)]);
        }
        cout << cnt << endl;
    }
}