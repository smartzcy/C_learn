#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int,map<int,int>>Map;
    int T;
    cin >> T;
    while(T--){
        int ai , ti , xi;
        cin >> ai >> ti >> xi;
        if(ai == 1) Map[ti][xi]++;
        else if(ai == 2) Map[ti][xi]--;
        else if(ai == 3){
            int count = 0;
            for(auto i : Map)
                if(i.first <= ti) count += i.second[xi];
                else break;
            cout << count << endl;
        }
    }
    return 0;
}