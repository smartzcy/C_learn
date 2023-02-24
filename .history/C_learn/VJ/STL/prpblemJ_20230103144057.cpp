#include<iostream>
#include<stack>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , flag = 1;
        stack<int> sta;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0 ; i < n;i++){
            if(s[i] == '(') sta.push(i);
            else if(s[i] == ')'){
                if(sta.size() == 0){
                    flag = 0;
                    break;
                }else{
                    sta.pop();
                }
            }
        }
        if(sta.size() != 0 || flag == 0) cout << "NO" << endl;
        else cout <<"YES" << endl;
    }
}