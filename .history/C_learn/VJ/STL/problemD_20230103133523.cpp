#include<iostream>
using namespace std;
int main(){
    int n , sum = 0;
    cin >> n;
    int k = n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(sum + num <= 0){
            k--;
        }else sum += num;
    }
    cout << k << endl;
}