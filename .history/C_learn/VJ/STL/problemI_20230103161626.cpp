#include<iostream>
#include<unordered_map>
#include<stack>
#include<set>
using namespace std;
int main(){
    int n;
    while(cin >> n , n != 0){
        int flag = 0;
        set<string> zong;
        unordered_map<string, set<string>> map1;
        for(int i = 0 ; i < n;i++){
            string a , b;
            cin >> a >> b;
            map1[a].insert(b);
            zong.insert(a);
            zong.insert(b);
        }
        for(auto i : map1){
            stack<string> sta;
            for(auto j : i.second){
                sta.push(j);
            }
            while(sta.size() != 0){
                i.second.insert(sta.top());
                for(auto j : map1[sta.top()]){
                    sta.push(j);
                }
                sta.pop();
            }
            if(i.second.size() == zong.size() - 1) {
                flag = 1;
                cout << "YES" << endl;
                break;
            }
        }
        if(flag == 0){
            cout << "NO" << endl;
        }
    }
}