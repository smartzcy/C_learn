#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    int n;
    map<string , int> map1;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        if(map1.find(str) != map1.end()){
            cout << str + to_string(map1[str]++) << endl;
        }else {
            map1[str] = 1;
            cout << "OK" << endl;
        }
    }
}