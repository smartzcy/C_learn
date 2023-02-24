#include <iostream>
using namespace std;
int main(){
    int n , k , flag = 0;
    cin >> n >> k;
    int nums[5000] , num[5000];
    for(int i = 0; i < n; i++){
        cin >> num[i];
        nums[num[i]]++;
        if(nums[num[i]] > k) flag = 1;
    }
    if(flag == 0) {
        cout << "YES" << endl;
        for(int i = 0 ; i < n;i++){
            cout << nums[num[i]] << " ";
        }
    }else cout << "NO" << endl;
}