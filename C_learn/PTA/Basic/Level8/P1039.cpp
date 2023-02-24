#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1 , s2;
    cin >> s1;
    cin >> s2;
    int count = s2.length();
    for(int i = 0 ; i < s2.length();i++){
        if(s1.find(s2[i]) != string::npos){
            if(s1.find(s2[i]) != s1.length()) s1 = s1.substr(0,s1.find(s2[i])) + s1.substr(s1.find(s2[i]) + 1);
            else s1 = s1.substr(0,s1.find(s2[i]));
            count--;
        }
    }
    if(count == 0){
        cout << "Yes " << s1.length() << endl;
    }else{
        cout << "No " << count << endl;
    }
}