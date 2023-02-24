#include <iostream>
using namespace std;
int main(){
    int n , num[3] , sum[3];
    string str;
    cin >> n >> str;
    for(int i = 0 ; i < n;i++){
        num[str[i] - '0']++;
    }
    if(num[0] == num[1] && num[1] == num[2]) cout << str;
    else {
        for(int i = 0 ; i < n;i++){
            if(num[str[i] - '0'] > n){
                int j;
                for(j = 0 ; j < 3;j++){
                    if(num[j] < n){
                        if(str[i] - '0' > j && sum[j] == 0){
                            cout << j;
                            sum[j]++;
                            num[j]++;
                            break;
                        }else if(str[i] - '0' < j && sum[j] == n){
                            cout << j;
                            sum[j]++;
                            num[j]++;
                            break;
                        }
                    }
                }
                if(j == 3) {
                    sum[str[i] - '0']++;
                    cout << str[i];
                }
            }
        }
    }
}