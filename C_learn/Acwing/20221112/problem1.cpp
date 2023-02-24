#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<string,int> map1;
    for(int i = 0 ; i < n;i++){
        string str;
        cin >> str;
        map1[str]++;
    }
    int max = -1;
    string name;
    for(auto i : map1){
        if(i.second > max) {
            max = i.second;
            name = i.first;
        }
    }
    cout << name;
}