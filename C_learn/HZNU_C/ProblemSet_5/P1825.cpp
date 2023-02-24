#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        if(num == 1){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}