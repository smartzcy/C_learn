#include <iostream>
#include <set>
using namespace std;
int main(){
    int T;
    cin >> T;
    string ss = "abcdefghijklmnopqrstuvwxyz";
    while(T--){
        int flag = 0;
        string str;
        cin >> str;
        set<char> set1;
        for(auto i : str){
            if(set1.find(i) != set1.end()){
                cout << "NO" << endl;
                flag = 1;
                break;
            }
            set1.insert(i);
        }
        if(flag == 0){
            string s = "";
            for(auto i : set1){
                s += i;
            }
            if(ss.find(s) != string::npos){
                cout << "YES" << endl;
            }else cout << "NO" << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}