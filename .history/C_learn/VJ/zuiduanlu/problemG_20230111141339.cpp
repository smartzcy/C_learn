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
            adj[str[2] - 'a' + 1].push_back(str[0] - 'a' + 1);
            d[str[0] - 'a' + 1]++;
        }
        queue<int> q;
        for(int i = 1 ; i <= n ;i++){
            if(d[i] == 0) q.push(i);
        }
    }
}