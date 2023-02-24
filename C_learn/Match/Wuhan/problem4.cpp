#include<iostream>
using namespace std;
int num[1000000];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> num[i];
            sum += num[i];
        }
        int max = num[n - 1];
        int num1 = 0;
        for(int i = n - 1; i >= 1 ;i--){
            num1 += num[i];
            if(max < num1){
                max = num1;
            }
        }
        cout << (514 * max + 114 * (sum - max) > 0 ? 514 * max + 114 * (sum - max) : 0) << endl;
    }
}