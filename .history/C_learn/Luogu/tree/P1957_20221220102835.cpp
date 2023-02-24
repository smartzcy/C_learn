#include<iostream>
#include<string>
using namespace std;
int main(){
    int T , flag = 0;
    cin >> T;
    while(T--){
        int a , b;
        string str , s;
        cin >> str >> a;
        if(str == "a"){
            cin >> b;
            flag = 1;
            s = to_string(a) + "+" + to_string(b) + "=" + to_string(a + b);
        }else if(str == "b"){
            flag = 2;
            cin >> b;
            s = to_string(a) + "-" + to_string(b) + "=" + to_string(a - b);
        }else if(str == "c"){
            flag = 3;
            cin >> b;
            s = to_string(a) + "8" + to_string(b) + "=" + to_string(a * b);
        }else{
            if(flag == 1){
                s = str + "+" + to_string(a) + "=" + to_string(a + atoi(str.c_str()));
            }else if(flag == 2){
                s = str + "-" + to_string(a) + "=" + to_string(atoi(str.c_str()) - a);
            }else if(flag == 3){
                s = str + "*" + to_string(a) + "=" + to_string(a * atoi(str.c_str()));
            }
        }
        cout << s << endl;
        cout << s.length() << endl;
    }
}