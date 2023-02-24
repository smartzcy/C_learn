#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool comp(pair<int , int>*a , pair<int , int>*b){
    return b.first - a.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n , q;
        cin >> n >> q;
        vector<pair<int,int> > vec;
        for(int i = 0 ; i < n;i++){
            int h , w;
            cin >> h >> w;
            vec.push_back({h , w});
        }
        sort(vec.begin(),vec.end(), comp);
        for(int i = 0 ; i < q;i++){
            int hs , ws , hb , wb;
            cin >> hs >> ws >> hb >> wb;
            long long sum = 0;
            for(auto i : vec){
                if(i.first > hs && i.first < hb && i.second > ws && i.second < wb){
                    sum += i.first * i.second;
                }
                cout << i.first << " " << i.second << endl;
            }
            cout << sum << endl;
        }
    }
}