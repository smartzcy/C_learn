#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n % 2 == 0){
            for(int i = n / 2 ; i < n ; i++){
                cout << i << " ";
            }
            for(int i = n + 1 ; i < n + n / 2 ; i++){
                cout << i << " ";
            }
            cout << endl;
        }else{
            int k = n + 1;
            for(int i = k / 2 ; i < k - 1;i++){
                cout << i + 1 << " ";
            }
            for(int i = k + 1 ; i < k + k / 2 ; i++){
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    }
}