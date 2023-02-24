#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int min1 = 10000;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        sum += num;
        min1 = min(min1 , num);
    }
    cout << sum - min1 * n;
}