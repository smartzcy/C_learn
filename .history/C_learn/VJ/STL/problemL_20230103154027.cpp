#include<iostream>
#include<set>
using namespace std;
pair<int , int> peo[300000];
int main(){
    int T;
    cin >> T;
    while(T--){
        multiset<int> s1 , s2;
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
                if(!(peo[i].first + peo[j].second == 2 || peo[i].second + peo[j].first == 2)){
                    ans++;
                    cout << i << " " << j << endl;
                }
            }
        }
        cout << ans << endl;
    }
}