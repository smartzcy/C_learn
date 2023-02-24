#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int p[200000];
int main(){
    int n , m;
    cin >> n;
    vector<int> vec[3];
    for(int i = 0 ; i < n ; i++) cin >> p[i];
    for(int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        vec[num - 1].push_back(p[i]);
    }
    for(int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        vec[num - 1].push_back(p[i]);
    }
    sort(vec[0].begin() , vec[0].end());
    sort(vec[1].begin() , vec[1].end());
    sort(vec[2].begin() , vec[2].end());
    cin >> m;
    int k[3] = {0 , 0 , 0};
    multiset<int> s;
    for(int i = 0 ; i < m ; i++){
        int num;
        cin >> num;
        int j = k[num - 1];
        for( ; j < vec[num - 1].size() ; j++){
            if(s.find(vec[num - 1][j]) == s.end()){
                k[num - 1] = j + 1;
                cout << vec[num - 1][j] << " ";
                s.insert(vec[num - 1][j]);
                break;
            }
        }
        if(j == vec[num - 1].size()) cout << "-1 ";
    }
}