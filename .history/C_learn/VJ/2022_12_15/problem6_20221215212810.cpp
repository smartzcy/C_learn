#include<iostream>
using namespace std;
int main(){
    int n , flag = 0;
    cin >> n;
    string s1 , s2;
    cin >> s1 >> s2;
    string str[6] = {"abca" , "acba" , "bacb" , "bcab" , "cabc" , "cbac"};
    string str1[6] = {"abc" , "acb" , "bac" , "bca" , "cab" , "cba"};
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
    for(int i = 0 ; i < 6 && flag == 0 ;i++){
        if(str1[i].find(s1) == string::npos && str1[i].find(s2) == string::npos){
            for(int j = 0 ; j < 3;j++){
                for(int k = 0 ; k < n ; k++){
                    cout << str1[i][j];
                }
            }
            break;
        }
    }
}