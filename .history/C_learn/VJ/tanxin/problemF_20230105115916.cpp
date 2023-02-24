#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    priority_queue<int , vector<int> , greater<int>> que;
    for(int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        que.push(num);
    }
    int ans = 0;
    while(que.size() != 1){
        int a = que.top();
        que.pop();
        int b = que.top();
        que.pop();
        que.push(a + b);
        ans += a + b;
    }
    cout << ans << endl;
}