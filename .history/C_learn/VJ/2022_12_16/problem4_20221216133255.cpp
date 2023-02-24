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
        cout << sum << endl;
        int i = 0 , j = n - 1;

    }
}