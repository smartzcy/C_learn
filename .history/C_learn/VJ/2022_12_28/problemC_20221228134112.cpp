#include<iostream>
#include<set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        set<char>set1;
        int ans = 0;
        cin >> str;
        for(int i = 0 ; i < str.length() ; i++){
            if(set1.find(str[i]) != set1.end()){
                ans += set1.size() - 1;
                set1.clear();
            }else{
                set1.insert(str[i]);
            }
        }
        ans += set1.size();
        cout << ans << endl;
    }
    return 0;
}