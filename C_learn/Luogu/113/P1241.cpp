#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char> s;
    string str1;
    string str;
    cin >> str;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '(' || str[i] == '['){
            s.push(str[i]);
        }else if(str[i] == ')'){
            str1 = "()" + str1;
            if(s.top() != '(' || s.empty()) {
                if(!s.empty() && s.top() == '[') {
                    str1 = "[]" + str1;
                    s.pop();
                }
            }else if(s.top() == '(') s.pop();
        }else if(str[i] == ']'){
            str1 = "[]" + str1;
            if(s.empty() || s.top() != '['){
                if(!s.empty() && s.top() == '(') {
                    str1 = "()" + str1;
                    s.pop();
                }
            }else if(s.top() == '[') s.pop();
        }
    }
    if(!s.empty()){
        stack<char> s1 = s;
        while(!s1.empty()){
            if(s1.top() == '(') str1 = "()" + str1;
            else if(s1.top() == '[') str1 = "[]" + str1;
            s1.pop();
        }
    }
    // if(!s.empty()){
    //     if(s.top() == '['){
    //         str1 = "[]" + str1;
    //     }else if(s.top() == '('){
    //         str1 = "()" + str1;
    //     }
    //     s.pop();
    // }
    cout << str1;
}