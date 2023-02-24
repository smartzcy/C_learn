#include<iostream>
using namespace std;
int main(){
    int n;
    char ch;
    cin >> n >> ch;
    int m = 1;
    int k = 3;
    while(n >= m * 2 - 1){
        m += k;
        k += 2;
    }
    int nm = k / 2;
    if(n <= 16 && n >= 7){
        nm--;
    }else if(n < 7){
        nm -= 2;
    }
    // cout << m << " " << k;
    if(nm % 2 != 0)nm++;
    if(n >= 49) nm += 2;
    for(int i = 1 ; i <= nm + 1;i++){
        for(int j = 1 ; j <= nm + 1;j++){
            if(i == 1 || i == nm + 1) cout << ch;
            else if(j < (nm + 2) / 2 - abs((nm + 2) / 2 - i)) cout << " ";
            else if(j <= (nm + 2) / 2 + abs((nm + 2) / 2 - i)) cout << ch;
            else break;
        }
        cout << endl;
    }
    if(n != (m - k + 2) * 2 - 1){
        cout << n - (m - k + 2) * 2 + 1;
    }
    return 0;
}