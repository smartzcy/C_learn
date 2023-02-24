#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.length() % 2 == 1) cout << "No";
    else{
        stack<char> sta;
        for(auto i : s){
            if(sta.empty()) sta.push(i);
            else{
                if(sta.top() == i) sta.pop();
                else sta.push(i);
            }
        }
        if(sta.empty()) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}