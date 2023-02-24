#include<iostream>
#include<set>
using namespace std;
int main(){
    int m = 0;
    set<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }
    for(auto i : s){
        if(s.find(i + 9) == s.end()){
            m++;
        }
    }
    cout << m;
}