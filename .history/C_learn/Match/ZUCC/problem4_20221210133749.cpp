#include<iostream>
#include<set>
using namespace std;
int main(){
    set<pair<int,int> > set;
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < k;i++){
        int a , b;
        cin >> a >> b;
        set.insert({a , b});
        set.insert({a + 1 , b});
        set.insert({a + 1 , b + 1});
    }
    cout << set.size();
}