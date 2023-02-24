#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int flag = 0;
    string s = "10X98765432";
    int num1[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    while(n--){
        string str;
        int k = 0;
        cin >> str;
        int num = 0;
        for(int i = 0 ; i < str.length() - 1;i++){
            if(str[i] >= '0' && str[i] <= '9'){
                num += (str[i] - '0') * num1[i];
            }else{
                if(flag == 0) cout << str;
                else cout << endl << str;
                flag = 1;
                k = 1;
                break;
            }
        }
        if(s[num % 11] != str[str.length() - 1] && k == 0) {
            if(flag == 0) cout << str;
            else cout << endl << str;
            flag = 1;
        }
    }
    if(flag == 0) cout << "All passed" << endl;
}