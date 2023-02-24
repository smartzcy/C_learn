#include<iostream>
using namespace std;
int main(){
    int n , sum = 0 , k = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num >= 0) {
            k++;
            sum += num;
        }
    }
    cout << k << endl;
}