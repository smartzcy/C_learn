#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num;
    int k = 0;
    int flag = 0;
    while(cin >> num){
        for(int i = 0; i < num;i++){
            cout << flag;
            k++;
            if(k % n == 0){
                cout << endl;
            }
        }
        if(k / n == n) break;
        if(flag == 0) flag = 1;
        else flag = 0;
    }
}