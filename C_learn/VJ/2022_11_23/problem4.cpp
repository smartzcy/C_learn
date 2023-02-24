#include<iostream>
#include<math.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    if(str.size() < 2){
        if((str[str.size() - 1] - '0') % 4 == 0) cout << "4";
        else cout << "0";
    }else{
        int n = str[str.size() - 1] - '0' + 10 * (str[str.size() - 2] - '0');
        if(n % 4 == 0) cout << "4";
        else cout << "0";
    }
}