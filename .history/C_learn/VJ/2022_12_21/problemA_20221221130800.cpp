#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , x;
        cin >> n >> x;
        if(n <= 2) cout << "1" << endl;
        else {
            for(int i = 0 ; i < 1000;i++){
                if(n >= i * x + 3 && n <= (i + 1) * x + 2){
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}