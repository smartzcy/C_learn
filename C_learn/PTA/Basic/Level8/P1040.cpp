#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    long long count1 = 0 , count2 = 0 , count3 = 0;
    for(int i = 0 ; i < str.length();i++){
        if(str[i] == 'T') count1++;
    }
    for(int i = 0 ; i < str.length();i++){
        if(str[i] == 'P') count2++;
        if(str[i] == 'T') count1--;
        if(str[i] == 'A') count3 += (count1 * count2) % 1000000007;
    }
    cout << count3 % 1000000007 << endl;
}