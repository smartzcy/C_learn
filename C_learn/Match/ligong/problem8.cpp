#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    map<int,vector<int>> map1;
    while(T--){
        int n , m;
        cin >> n >> m;
        for(int i = 1 ; i <= n;i++){
            int l , r;
            cin >> l >> r;
            for(int j = l ; j <= r;j++){
                if(map1.find(j) != map1.end()){
                    map1[j].push_back(i);
                }else{
                    vector<int> vec;
                    vec.push_back(i);
                    map1.insert(pair<int,vector<int>>{j,vec});
                }
            }
        }
        int min1 = map1.size();
        for(auto i : map1){
            int num = map1.size();
            if(i.second.size() <= 2){
                for(auto j : map1){
                    if(j.second.size() == i.second.size()){
                        int k = 0;
                        for(; k < i.second.size(); k++){
                            if(j.second[k] != i.second[k]){
                                break;
                            }
                        }
                        if(k == i.second.size()){
                            num--;
                        }
                    }else if(j.second.size() < i.second.size()){
                        for(auto k : i.second){
                            if(k == j.second[0]) num--;
                        }
                    }
                }
                min1 = min(min1,num);
            }
        }
        cout << min1 << endl;
    }
}