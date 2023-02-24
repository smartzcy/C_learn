#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
struct People{
    int first;
    int second;
    int x , y;
}peo[300000];
set<int> s1 , s2;
bool way(int i , int j){
    if(peo[i].first + peo[j].second == 2 || peo[i].second + peo[j].first == 2) return false;
    else if(peo[i].first == 1 && peo[j].first == 1){
        int min1 = min(peo[i].y , peo[j].y);
        if(*s2.lower_bound(min1) > max(peo[i].y , peo[j].y)) return true;
        else return false;
    }else if(peo[i].second == 1 && peo[j].second == 1){
        int min1 = min(peo[i].x , peo[j].x);
        if(*s1.lower_bound(min1) > max(peo[i].x , peo[j].x)) return true;
        else return false;
    }else{
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        s1.insert(0);
        s2.insert(0);
        s1.insert(1000000);
        s2.insert(1000000);
        int n , m , k;
        cin >> n >> m >> k;
        for(int i = 0 ; i < n ;i++){
            int num;
            cin >> num;
            s1.insert(num);
        }
        for(int i = 0 ; i < m ; i++){
            int num;
            cin >> num;
            s2.insert(num);
        }
        for(int i = 0 ; i < k ; i++){
            int x , y;
            cin >> x >> y;
            peo[i].x = x;
            peo[i].y = y;
            if(s1.find(x) != s1.end()) peo[i].first = 1;
            else peo[i].first = 0;
            if(s2.find(y) != s2.end()) peo[i].second = 1;
            else peo[i].second = 0;
        }
        int ans = 0;
        for(int i = 0 ; i < k ;i++)
            for(int j = i + 1 ; j < k;j++)
                if(way(i , j))
                    ans++;
        cout << ans << endl;
        s1.clear();
        s2.clear();
    }
}