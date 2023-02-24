#include<iostream>
using namespace std;
int n;
bool way1(string s1[10] , string s2[10]){
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n;j++){
            if(s1[i][j] != s2[j][n - i - 1]) return false;
        }
    }
    return true;
}
bool way2(string s1[10] , string s2[10]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(s1[i][j] != s2[n - i - 1][n - j - 1]) return false;
        }
    }
    return true;
}
bool way3(string s1[10] , string s2[10]){
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n;j++){
            if(s1[i][j] != s2[n - j - 1][i]) return false;
        }
    }
    return true;
}
int main(){
    cin >> n;
    string str1[10];
    string str2[10];
    for(int i = 0 ; i < n;i++){
        cin >> str1[i];
    }
    for(int i = 0 ; i < n;i++){
        cin >> str2[i];
    }
    if(way1(str1 , str2)) cout << "1";
    else if(way2(str1 , str2)) cout << "2";
    else if(way3(str1 , str2)) cout << "3";
}