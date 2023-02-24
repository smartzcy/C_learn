#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n , m;
vector<int> adj[27];
int d[27] , d1[27];
vector<int> ans;
bool way(){
    queue<int> q;
    for(int i = 1 ; i <= n ;i++){
        if(d[i] == 0) q.push(i);
        d1[i] = d[i];
    }
    if(q.size() > 1) return 0;
    else{
        while(!q.empty()){
            int now = q.front();
            q.pop();
            ans.push_back(now);
            for(int i = 0 ; i < adj[now].size() ; i++){
                d1[adj[now][i]]--;
                if(d1[adj[now][i]] == 0) q.push(adj[now][i]);
            }
        }
    }
    if(ans.size() == n) return 1;
    else return -1;
}
int main(){
    while(cin >> n >> m , n != 0 && m != 0){
        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            d[i] = 0;
        }
        int flag = 1;
        for(int i = 0 ; i < m;i++){
            string str;
            cin >> str;
            if(flag == -1) continue;
            adj[str[2] - 'A' + 1].push_back(str[0] - 'A' + 1);
            d[str[0] - 'A' + 1]++;
            ans.clear();
            flag = way();
            cout << flag << endl;
            if(flag == -1) cout << "Inconsistency found after " << i + 1 << " relations." << endl;
        }
        if(flag == 1){
            cout << "Sorted sequence determined after 4 relations: ";
            for(int i = ans.size() - 1 ; i >= 0 ;i--) cout << (char)(ans[i] + 'A' - 1);
            cout << "." << endl;
        }else if(flag == 0) cout << "Sorted sequence cannot be determined." << endl;
    }
}