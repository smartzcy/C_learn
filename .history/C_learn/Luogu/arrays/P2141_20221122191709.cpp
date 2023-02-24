#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    set<int>set1;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        set1.insert(num);
    }
    int sum = 0;
    for(auto i : set1){
        for(auto j : set1){
            if(i != j && set1.find(i + j) != set1.end()) sum++;
        }
    }
    cout << sum / 2;
}