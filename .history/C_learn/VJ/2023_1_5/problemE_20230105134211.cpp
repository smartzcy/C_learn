#include<iostream>
#include<algorithm>
using namespace std;
int nums[1000];
int way(int n){
    if(n == 1 || n == 2) return nums[n - 1];
    else if(n == 3) return nums[0] + nums[1] + nums[2];
    else return way(n - 2) + min(nums[0] + 2 * nums[1] + nums[n - 1] , nums[0] * 2 + nums[n - 1] + nums[n - 2]);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ;i++) cin >> nums[i];
        cout << way(n) << endl;
    }
    return 0;
}
/*
a b c d
a + d,a, a + c,a ,a + b
2a + d + c
a + b ,a , c + d, b ,a + b
a + 2b + d
*/