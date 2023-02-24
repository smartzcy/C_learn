#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int double_odd = 0;
        int double_even = 0;
        int int_odd = 0;
        int int_even = 0;
        for(int i = 1 ; i <= n ; i++){
            int num;
            cin >> num;
            if(num % 2 == 0){
                if(i % 2 == 0) double_even++;
                else double_odd++;
            }else{
                if(i % 2 == 0) int_even++;
                else int_odd++;
            }
        }
        if(double_odd * int_odd == 0 && double_even * int_even == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}