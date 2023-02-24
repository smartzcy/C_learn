#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const void *a, const void *b){
    return ((pair<int , vector<int> > *) a)->first - ((pair<int , vector<int> > *) b)->first;
}
int main(){
    vector<pair<int,vector<int>>> vec;
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        vector<int> v;
        vec.push_back({num , v});
        for(int j = 1; j < m ;j++){
            cin >> num;
            vec[i].second.push_back(num);
        }
    }
    sort(vec.begin(), vec.end() , cmp);
    for(auto i : vec){
        cout << i.first << "";
        for(auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }
}