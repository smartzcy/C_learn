#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n , m;
vector<int> adj[27];
int d[27];
int main(){
    while(cin >> n >> m , n != 0 && m != 0){
        for(int i = 0 ; i < m;i++){
            string str;
            cin >> str;
            adj[str[2] - 'A' + 1].push_back(str[0] - 'A' + 1);
            d[str[0] - 'A' + 1]++;
        }
        queue<int> q;
        for(int i = 1 ; i <= n ;i++){
            if(d[i] == 0) q.push(i);
        }
        if(q.size() > 1) cout << "Sorted sequence cannot be determined." << endl;
        else{
            vector<int> ans;
            while(!q.empty()){
                int now = q.front();
                q.pop();
                ans.push_back(now);
                for(int i = 0 ; i < adj[now].size() ; i++){
                    d[adj[now][i]]--;
                    if(d[adj[now][i]] == 0) q.push(adj[now][i]);
                }
            }
            cout << "Sorted sequence determined after 4 relations: ";
            for(int i = ans.size() - 1 ; i >= 0 ; i--){
                cout << (char)(ans[i] + 'A' - 1);
            }
            cout << "." << endl;
        }
    }
}