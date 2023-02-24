#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int,int> map1;
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        map1[num]++;
    }
    int min1 = 0;
    for(auto i : map1){
        
    }
}