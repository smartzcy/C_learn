#include<iostream>
#include<stack>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            int num;
            cin >> num;
            st.push(num);
        }
        int flag = 0;
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            if(num != st.top()){
                flag = 1;
            }
            st.pop();
        }
        if(flag == 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}