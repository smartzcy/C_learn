#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> vec;
    vec.push_back(1);
    for(int i = 2 ; i <= N;i++){
        int k , p;
        cin >> k >> p;
        vector<int>::iterator it = find(vec.begin(), vec.end(), k);
        if(p == 1) it++;
        vec.insert(it , i);
    }
    cin >> N;
    for(int i = 0 ; i < N; i++){
        int num;
        cin >> num;
        vector<int>::iterator it = find(vec.begin(), vec.end() , num);
        if(it != vec.end()) vec.erase(it);
    }
    for(auto i : vec) cout << i << " ";
    return 0;
}