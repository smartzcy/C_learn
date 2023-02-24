#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(str[i] == 'L') sum += i;
            else sum += n - i - 1;
        }
        int i = 0 , j = n - 1;
        int k = n;
        while(i < j){
            if(str[i] == 'L'){
                sum = sum - i + n - i - 1;
                cout << sum << " ";
                k--;
            }
            if(str[j] == 'R'){
                sum = sum - (n - j - 1) + j;
                cout << sum << " ";
                k--;
            }
            i++;
            j--;
        }
        for(int i = 0  ; i < k;i++){
            cout << sum << " ";
        }
        cout << sum << endl;
    }
}