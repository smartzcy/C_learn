#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        for(int i = 0 ; i < 4;i++){
            string str;
            cin >> str;
            if(str[2] == 'T') cout << str[0] - 'A' + 1;
        }
    }
    cout << endl;
    return 0;
}