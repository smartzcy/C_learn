#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    while (cin >> n , n != 0){
        string str[1001];
        for(int i = 0 ; i < n ;i++){
            cin >> str[i];
        }
        int k = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n ;j++){
                if(str[i].length() > str[j].length()) continue;
                if(i != j && str[i] == str[j].substr(0,str[i].length())){
                    cout << "NO" << endl;
                    k = 1;
                    break;
                }
            }
            if(k == 1) break;
        }
        if(k == 0){
            cout << "YES" << endl;
        }
    }
    return 0;
}