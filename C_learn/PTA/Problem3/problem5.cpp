#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int>map;
    int T;
    cin >> T;
    int max = 0,min = 1000000;
    while(T--){
        int n;
        cin >> n;
        if(map.find(n) != map.end()){
            map[n]++;
        }else {
            map.insert(pair<int,int>(n,1));
        }
        
        max = max > n ? max : n;
        min = min < n ? min : n;
    }
    cout << min << " " << map[min] << endl;
    cout << max << " " << map[max] << endl;
}