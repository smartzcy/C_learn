#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1; i <= 2 * n - 1;i++){
            for(int j = 0 ; j < 2 * n;j++) cout << " ";
            for(int j = 1 ; j <= n - abs(n - i);j++){
                if(j == 1 || j == n - abs(n - i)) cout << "*";
                else cout << " ";
            }
            cout << endl;
        }
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < 2 * n ;j++) cout << " ";
            cout << "*" << endl;;
        }
        for(int i = 1 ; i <= 4 * n + 1;i++) cout << "*";
        cout << endl;
        for(int i = 1 ; i <= 4 * n;i++){
            if(i == 2 || i == 4 * n) cout << "*";
            else cout << " ";
        }
        cout << endl;
        for(int i = 1 ; i <= 4 * n - 1;i++){
            if(i <= 2) cout << " ";
            else cout << "*";
        }
        cout << endl;
        if(T != 0)cout << endl;
    }
}