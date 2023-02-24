#include <iostream>
using namespace std;
int nums[5000] , num[5000] , sum[5000][5000];
int main(){
    int n , k , flag = 0;
    cin >> n >> k;
    if(n < k) flag = 1;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        nums[num[i]]++;
        if(nums[num[i]] > k) flag = 1;
    }
    if(flag == 0) {
        cout << "YES" << endl;
        for(int i = 0 ; i < n;i++){
            if(i < k) {
                cout << i + 1 << " ";
                sum[i + 1][num[i]] = 1;
            }else{
                for(int j = 0 ; j < k;j++){
                    if(sum[j + 1][num[i]] == 0){
                        cout << j + 1 << " ";
                        sum[j + 1][num[i]] = 1;
                        break;
                    }
                }
            }
        }
    }else cout << "NO" << endl;
}