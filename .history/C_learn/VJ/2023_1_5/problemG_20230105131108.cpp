#include <iostream>
#include<queue>
using namespace std;
int main(){
    long long n , ans = 0 , num;
    cin >> n;
    priority_queue<int , vector<int> , greater<int> > que;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        if(!que.empty() && que.top() < num) {
            ans += num - que.top();
            que.pop();
            que.push(num);
        }
        que.push(num);
    }
    cout << ans << endl;
    return 0;
}