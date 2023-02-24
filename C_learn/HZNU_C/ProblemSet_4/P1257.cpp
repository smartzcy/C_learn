#include<iostream>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        int k = 0;
        int i = 0;
        while (1){
            i++;
            k = k % n * 10 + 1;
            if(k % n == 0){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}