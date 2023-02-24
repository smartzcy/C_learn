#include<iostream>
#include<set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , flag = 1;
        cin >> n;
        set<char> set;
        string str;
        cin >> str;
        for(int i = 0 ; i < n;i++){
            if(str[i] == 'T' || str[i] == 'i' || str[i] == 'm' || str[i] == 'u' || str[i] == 'r'){
                if(set.find(str[i]) != set.end()){
                    flag = 0;
                    break;
                }
                set.insert(str[i]);
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 1 && set.size() == 5) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}