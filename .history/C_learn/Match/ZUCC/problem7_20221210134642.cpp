#include<iostream>
#include<set>
using namespace std;
set<pair<int,int> > s;
int n , k;
void way(int a , int b){
    s.insert({a , b});
    s.insert({a + 1 , b});
    s.insert({a + 1 , b + 1});
    if(a + 1 == n) return ;
    way(a + 1 , b);
    way(a + 1 , b + 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0 ; i < k;i++){
        int a , b;
        cin >> a >> b;
        way(a , b);
        if(s.find({a , b - 1}) != s.end()){
            s.insert({a - 1 , b - 1});
        }else if(s.find({a , b + 1}) != s.end()){
            s.insert({a - 1 , b});
        }
    }
    cout << s.size();
}