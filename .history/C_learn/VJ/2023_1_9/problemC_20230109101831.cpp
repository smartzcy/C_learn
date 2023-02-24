#include<iostream>
#include<queue>
#include<string>
#include<vector>
// #include<unordered_map>
using namespace std;
int n = 5 , num[6][6] , vis[10000];
pair<int,int> pp[6][6];
// unordered_map<pair<int, int>,pair<int, int>> map1;
void bfs(){
    queue<pair<int,int>> que;
    que.push({0,0});
    while(que.size()){
        pair<int,int> p = que.front();
        que.pop();
        if(num[p.first + 1][p.second] == 0 && p.first + 1 < n){
            que.push({p.first + 1,p.second});
            pp[p.first + 1][p.second] = {p.first,p.second};
            // map1[{p.first + 1,p.second}] = {p.first,p.second};
        }
        if(num[p.first][p.second + 1] == 0 && p.second + 1 < n){
            que.push({p.first,p.second + 1});
            pp[p.first][p.second + 1] = {p.first,p.second};
            // map1[{p.first,p.second + 1}] = {p.first , p.second};
        }
    }
}
int main(){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> num[i][j];
    bfs();
    pair<int,int> p = {4,4};
    vector<string> vec;
    while(p.first != 0 || p.second != 0){
        string s = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
        vec.push_back(s);
        p = pp[p.first][p.second];
    }
    cout << "(0, 0)" << endl;
    for(int i = vec.size() - 1 ; i >= 0 ;i--) cout << vec[i] << endl;
}