#include<iostream>
#include<map>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        map<char,int> map1;
        map<char,int> map2;
        map<string,int> map3;
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            string str;
            cin >> str;
            map1[str[0]]++;
            map2[str[1]]++;
            map3[str]++;
        }
        for(auto i : map3){
            sum += (map1[i.first[0]] - i.second) * i.second;
            sum += (map2[i.first[1]] - i.second) * i.second;
        }
        cout << sum / 2 << endl;
    }
}