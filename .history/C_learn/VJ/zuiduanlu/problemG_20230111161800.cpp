// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int N = 30;
// int n, m, in[N];
// char ans[N], q[N];
// vector<int> e[N];
// int topoSort(){
//     int d[N], ret = 1;
//     memcpy(d, in, sizeof(d));
//     int front = 0, rear = 0, p = 0;
//     for (int i = 0; i < n; ++i)
//         if (d[i] == 0)
//             q[rear++] = i;
//     while (front < rear){
//         if (rear - front > 1) ret = 0;
//         int cur = q[front++];
//         ans[p++] = 'A' + cur;
//         for (int i = 0; i < e[cur].size(); ++i){
//             int j = e[cur][i];
//             if ((--d[j]) == 0) q[rear++] = j;
//         }
//     }
//     if (p < n) return -1;
//     ans[p] = 0;
//     return ret;
// }
// int main(){
//     char a, b;
//     while (scanf("%d%d", &n, &m), n || m){
//         for (int i = 0; i < n; ++i) e[i].clear();
//         memset(in, 0, sizeof(in));
//         int flag = 0;
//         for (int i = 0; i < m; ++i){
//             scanf(" %c<%c", &a, &b);
//             if (flag)  continue;
//             a -= 'A', b -= 'A';
//             e[a].push_back(b);
//             ++in[b];
//             flag = topoSort();
//             if (flag == 1) printf("Sorted sequence determined after %d relations: %s.\n", i + 1, ans);
//             if (flag == -1) printf("Inconsistency found after %d relations.\n", i + 1);
//         }
//         if (!flag) printf("Sorted sequence cannot be determined.\n");
//     }
//     return 0;
// }

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n , m;
vector<int> adj[27];
int d[27] , d1[27];
vector<int> ans;
int way(){
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
            ans.clear();
            d[i] = 0;
        }
        int flag = 0;
        for(int i = 0 ; i < m;i++){
            string str;
            cin >> str;
            if(flag) continue;
            adj[str[2] - 'A' + 1].push_back(str[0] - 'A' + 1);
            d[str[0] - 'A' + 1]++;
            ans.clear();
            flag = way();
            if(flag == -1) cout << "Inconsistency found after " << i + 1 << " relations." << endl;
            if(flag == 1){
                cout << "Sorted sequence determined after " << i + 1 << " relations: ";
                for(int i = ans.size() - 1 ; i >= 0 ;i--) cout << (char)(ans[i] + 'A' - 1);
                cout << "." << endl;
            }
        }
        if(flag == 0) cout << "Sorted sequence cannot be determined." << endl;
    }
}