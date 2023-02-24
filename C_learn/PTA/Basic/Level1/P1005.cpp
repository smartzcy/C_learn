#include<iostream>
using namespace std;
int main(){
    int n;
    int num[101] = {0};
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int m;
        cin >> m;
        num[m] = 1;
    }
    for(int i = 1 ; i <= 100;i++){
        if(num[i]){
            int m = i;
            while(m != 1){
                if(m % 2 == 0) m /= 2;
                else m = (m * 3 + 1) / 2;
                if(m <= 100 && num[m]){
                    num[m] = 0;
                    n--;
                    if(m < i) break;
                }
            }
        }
        
    }
    for(int i = 100 ; i >= 1;i--){
        if(num[i]){
            cout << i;
            if(n-- != 1) cout << " ";
            else cout << endl;
        }
    }
}