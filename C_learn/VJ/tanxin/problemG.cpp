#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
pair<int , int> num[100050];
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> num[i].first >> num[i].second;
    sort(num , num + n);
    priority_queue<int , vector<int> , greater<int>> que;
    long long ans = 0;
    for(int i = 0 ; i < n ;i++){
        if(que.size() >= num[i].first){
            if(que.top() < num[i].second){
                int sum = que.top();
                que.pop();
                que.push(num[i].second);
                ans = ans - sum + num[i].second;
            }
        }else{
            que.push(num[i].second);
            ans += num[i].second;
        }
    }
    cout << ans << endl;
}