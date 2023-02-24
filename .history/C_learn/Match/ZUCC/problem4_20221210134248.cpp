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
    cin >> n >> k;
    for(int i = 0 ; i < k;i++){
        int a , b;
        cin >> a >> b;
        way(a , b);
    }
    cout << s.size();
}