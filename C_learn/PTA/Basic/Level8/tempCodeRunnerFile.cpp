#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    long long count = 0;
    for(int i = 0 ; i < str.length() - 2;i++){
        if(str[i] == 'P'){
            if(str.substr(i + 1).find('A') != string::npos){
                if(str.substr(str.substr(i + 1).find('A')).find('T') != string::npos) count++;
            }
        }
    }
    cout << count % 1000000007 << endl;
}