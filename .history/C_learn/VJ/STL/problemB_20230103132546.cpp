#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int x;
        string str;
        cin >> x >> str;
        if(str == "FIFO"){
            queue<int> que;
            for(int i = 0 ; i < x ;i++){
                string s;
                cin >> s;
                if(s == "IN"){
                    int num;
                    cin >> num;
                    que.push(num);
                }else if(s == "OUT"){
                    if(que.size() == 0) cout << "None" << endl;
                    else {
                        cout << que.front() << endl;
                        que.pop();
                    }
                }
            }
        }else if(str == "FILO"){
            stack<int> sta;
            for(int i = 0 ; i < x ; i++){
                string s;
                cin >> s;
                if(s == "IN"){
                    int num;
                    cin >> num;
                    sta.push(num);
                }else if(s == "OUT"){
                    if(sta.size() == 0) cout << "None" << endl;
                    else {
                        cout << sta.top() << endl;
                        sta.pop();
                    }
                }
            }
        }
    }
}