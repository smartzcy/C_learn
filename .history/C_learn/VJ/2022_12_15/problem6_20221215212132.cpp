#include<iostream>
using namespace std;
int main(){
    int n , flag = 0;
    cin >> n;
    string s1 , s2;
    cin >> s1 >> s2;
    string str[6] = {"abca" , "acba" , "bacb" , "bcab" , "cabc" , "cbac"};
    cout << "YES" << endl;
    for(int i = 0 ; i < 6 ;i++){
        if(str[i].find(s1) == string::npos && str[i].find(s2) == string::npos){
            for(int j = 0 ; j < n ;j++){
                cout << str[i].substr(0,3);
            }
            flag = 1;
            break;
        }
    }
}