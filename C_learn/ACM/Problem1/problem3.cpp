#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        int m = n;
        if(n % 2 != 0) m--;
        for(int i = 0; i < m / 2;i++){
            cout << m / 2 - i << " " << m - i;
            if(i != m / 2 - 1) cout << " ";
        }
        if(n % 2 != 0) cout << " " << n << endl;
        else cout << endl;
    }
    return 0;
}