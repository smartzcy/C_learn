#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , num[200001];
        cin >> n;
        for(int i = 1 ; i <= n;i++){
            if((n - i + 1) % 2 == 0){
                num[(i + n - 1) / 2] = i;
            }else{
                num[(i + n) / 2] = i;
            }
        }
        for(int i = 1 ; i <= n ;i++){
            cout << num[i] << " ";
        }
        cout << endl;
    }
}