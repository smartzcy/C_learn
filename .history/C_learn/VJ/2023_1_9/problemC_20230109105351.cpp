#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
// #include<unordered_map>
using namespace std;
int n = 5 , num[6][6] , vis[10000];
pair<int,int> pp[6][6];
// unordered_map<pair<int, int>,pair<int, int>> map1;
void bfs(){
    queue<pair<int,int> > que;
    pair<int,int> pa;
    pa.first = 0;
    pa.second = 0;
    que.push(pa);
    while(que.size()){
        pair<int,int> p = que.front();
        que.pop();
        if(num[p.first + 1][p.second] == 0 && p.first + 1 < n){
            pair<int,int>p2;
            p2.first = p.first + 1;
            p2.second = p.second;
            que.push(p2);
            pp[p.first + 1][p.second].first = p.first;
            pp[p.first + 1][p.second].second = p.second;
            // map1[{p.first + 1,p.second}] = {p.first,p.second};
        }
        if(num[p.first][p.second + 1] == 0 && p.second + 1 < n){
            pair<int,int>p2;
            p2.first = p.first;
            p2.second = p.second + 1;
            que.push(p2);
            pp[p.first][p.second + 1].first = p.first;
            pp[p.first][p.second + 1].second = p.second;
            // map1[{p.first,p.second + 1}] = {p.first , p.second};
        }
    }
}
int main(){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> num[i][j];
    bfs();
    pair<int,int> p;
    p.first = 4;
    p.second = 4;
    vector<pair<int,int>> vec;
    while(p.first != 0 || p.second != 0){
        vec.push_back(p);
        p = pp[p.first][p.second];
    }
    cout << "(0, 0)" << endl;
    for(int i = vec.size() - 1 ; i >= 0 ;i--) cout << "(" << vec[i].first << ", " << vec[i].second << ")" << endl;
}