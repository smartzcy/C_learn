#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m , flag = 0;
        cin >> n >> m;
        for(int i = 0 ; i < n;i++){
            int x1 , x2 , x3 , x4;
            cin >> x1 >> x2 >> x3 >> x4;
            if(x2 == x3) flag = 1;
        }
        if(m % 2 == 1){
            cout << "NO" << endl;
        }else{
            if(flag == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}