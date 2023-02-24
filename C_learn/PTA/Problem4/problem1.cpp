#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1 ; i <= n;i++){
        for(int j = 1 ; j <= n;j++){
            int num;
            cin >> num;
            if(i != n && j != n && (i + j) != (n + 1)) sum += num;
        }
    }
    cout << sum;
}