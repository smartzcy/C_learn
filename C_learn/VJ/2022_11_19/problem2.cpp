#include<iostream>
#include<map>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int m;
        cin >> m;
        map<int, int> map1;
        for(int i = 0 ; i < m ; i++){
            int num;
            cin >> num;
            map1[num]++;
        }
        int max = 0;
        int wei = 0;
        for(auto i : map1){
            if(max < i.second){
                wei = i.first;
                max = i.second;
            }
        }
        if(max < 3 || m == 1) cout << "-1" << endl;
        else cout << wei << endl;
    }
}