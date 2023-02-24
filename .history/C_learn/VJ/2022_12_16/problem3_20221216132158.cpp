#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        map<string , vector<int>> map1;
        int n;
        cin >> n;
        for(int i = 0 ; i < 3;i++){
            for(int j = 0 ; j < n;j++){
                string s;
                cin >> s;
                map1[s].push_back(i);
            }
        }
        int sum[3] = {0 , 0 , 0};
        for(auto i : map1){
            if(i.second.size() == 2){
                for(auto j : i.second){
                    sum[j]++;
                }
            }else if(i.second.size() == 1){
                for(auto j : i.second){
                    sum[j] += 2;
                }
            }
        }
        for(int i = 0 ; i < 3 ;i++){
            cout << sum[i];
            if(i != 2) cout << " ";
            else cout << endl;
        }
    }
}