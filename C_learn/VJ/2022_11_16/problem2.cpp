#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> map1;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int num;
        cin >> num;
        map1[num]++;
    }
    auto it = map1.end();
    it--;
    for(;it != map1.begin();it--){
        if(it->second % 2 == 1) {
            break;
        }
    }
    if(it->second % 2 == 1){
        cout << "Conan";
    }else cout << "Agasa";
}