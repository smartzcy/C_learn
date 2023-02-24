#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const string& a, const string& b){
    return a + b < b + a;
}
int main(){
    int n;
    string str[30];
    cin >> n;
    for(int i = 0 ; i < n;i++) cin >> str[i];
    sort(str , str + n , cmp);
    for(int i = n - 1 ; i >= 0; i--) cout << str[i];
}