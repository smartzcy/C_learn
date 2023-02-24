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
        if(*s2.lower_bound(min1) > max(peo[i].y , peo[j].y) || *s2.lower_bound(min1) < min1) return true;
        else return false;
    }else if(peo[i].second == 1 && peo[j].second == 1){
        int min1 = min(peo[i].x , peo[j].x);
        if(*s1.lower_bound(min1) > max(peo[i].x , peo[j].x) || *s1.lower_bound(min1) < min1) return true;
        else return false;
    }else{
        return true;
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
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
            int k1 , k2;
            if(s1.find(x) != s1.end()) k1 = 1;
            else k1 = 0;
            if(s2.find(x) != s2.end()) k2 = 1;
            else k2 = 0;
            peo[i].first = k1;
            peo[i].second = k2;
        }
        int ans = 0;
        for(int i = 0 ; i < k ;i++){
            for(int j = i + 1 ; j < k;j++){
                if(way(i , j)){
                    ans++;
                    cout << i << " " << j << endl;
                    cout << peo[i].first << " " << peo[i].second << endl;
                    cout << peo[j].first << " " << peo[j].second << endl << endl;
                }
            }
        }
        cout << ans << endl;
        s1.clear();
        s2.clear();
    }
}