#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int>map1;
    int n;
    cin >> n;
    int max = 0, max_x = 0;
    while(n--){
        int x , num;
        cin >> x >> num;
        map1[x] += num;
        if(map1[x] >= max){
            max = map1[x];
            max_x = x;
        }
    }
    cout << max_x << " " << max << endl;
}