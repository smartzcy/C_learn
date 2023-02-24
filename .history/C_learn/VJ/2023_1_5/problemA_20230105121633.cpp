#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num1 , ans = 0 , now = 1;
    cin >> num1;
    for(int i = 1; i < n ; i++){
        int num;
        cin >> num;
        if(num1 == num) now++;
        else{
            if(now >= 2) ans += 2;
            else ans += 1;
            now = 1;
            num1 = num;
        }
    }
    if(now >= 2) ans += 2;
    else ans += 1;
    cout << ans << endl;
}