#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int min = INT_MAX;
        int n1 = 0;
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            if(i == 0){
                min = num;
                n1 = num;
            }
            if(min > num) min = num;
        }
        if(n1 != min) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}