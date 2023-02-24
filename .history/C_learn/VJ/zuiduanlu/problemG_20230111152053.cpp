#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n , m;
vector<int> adj[27];
int d[27] , d1[27];
char ans[27];
int way(){
    char q[27];
    int front = 0 , rear = 0 , p = 0 , ret = 1;
    for(int i = 1 ; i <= n ;i++){
        if(d[i] == 0) q[rear++] = i;
        d1[i] = d[i];
    }
    while(front < rear){
        if(rear - front > 1) ret = 0;
        int cur = q[front++];
        ans[p++] = 'A' + cur;
        for(int i = 0 ; i < adj[cur].size();i++){
            int j = adj[cur][i];
            if((--d1[j]) == 0) q[rear++] = j;
        }
    }
    if(p > n) return -1;
    ans[p] = 0;
    return ret;
}
int main(){
    while(cin >> n >> m , n != 0 && m != 0){
        for(int i = 1 ; i <= n ; i++){
            adj[i].clear();
            d[i] = 0;
        }
        int flag = 0;
        for(int i = 0 ; i < m;i++){
            string str;
            cin >> str;
            if(flag) continue;
            adj[str[0] - 'A'].push_back(str[2] - 'A');
            d[str[2] - 'A']++;
            flag = way();
            if(flag == -1) cout << "Inconsistency found after " << i + 1 << " relations." << endl;
            if(flag == 1){
                cout << "Sorted sequence determined after " << i + 1 << " relations: ";
                cout << ans;
                cout << "." << endl;
            }
        }
        if(flag == 0) cout << "Sorted sequence cannot be determined." << endl;
    }
}