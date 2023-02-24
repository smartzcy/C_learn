#include<iostream>
#include<string>
using namespace std;
int main(){
    char ch1[] = {"bcdefghijklmnopqrstuvwxyza"};
    char ch2[] = {"BCDEFGHIJKLMNOPQRSTUVWXYZA"};
    string str;
    getline(cin,str);
    for(int i = 0 ; i < str.length();i++){
        if(str[i] <= 'Z' && str[i] >= 'A'){
            cout << ch1[str[i] - 'A'];
        }else if(str[i] <= 'z' && str[i] >= 'a'){
            cout << ch2[str[i] - 'a'];
        }else{
            cout << str[i];
        }
    }
    cout << endl;
    return 0;
}