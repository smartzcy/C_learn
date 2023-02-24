#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n , sum = 0 , k = 0;
    cin >> n;
    priority_queue<int> que;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        sum += num;
        if(num < 0) que.push(num);
        while(sum < 0 && !que.empty()){
            num += -que.top();
            que.pop();
            k++;
        }
    }
    cout << n - k;
}