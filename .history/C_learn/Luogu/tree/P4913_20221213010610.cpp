#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> vec;
int FindDeep(int n){
    if(vec[n - 1].first == 0 && vec[n - 1].second == 0) return 1;
    return max(vec[n - 1].first, vec[n - 1].second) + 1;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1 ;  i <= n;i++){
        int a , b;
        cin >> a >> b;
        vec.push_back(pair<int,int>(a,b));
    }
    cout << FindDeep(1);
}