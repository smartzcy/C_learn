#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 0 , sum = 0;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        int m = num;
        while(num > 0){
            if(num % 10 == 4) break;
            num /= 10;
        }
        if(num == 0) {
            count++;
            sum += m;
        }
    }
    cout << sum << endl;
    cout << count;
}