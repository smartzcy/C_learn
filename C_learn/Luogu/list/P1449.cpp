#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<int> st;
    int num = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] <= '9' && s[i] >= '0'){
            num = num * 10 + s[i] - '0';
        }else if(s[i] == '.'){
            st.push(num);
            num = 0;
        }else if(s[i] != '@'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(s[i] == '-'){
                st.push(b - a);
            }else if(s[i] == '+'){
                st.push(b + a);
            }else if(s[i] == '*'){
                st.push(a * b);
            }else if(s[i] == '/'){
                st.push(b / a);
            }
        }
    }
    cout << st.top();
}