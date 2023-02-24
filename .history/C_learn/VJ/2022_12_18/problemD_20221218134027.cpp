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
            if(num[str[i] - '0'] > n / 3){
                int j;
                for(j = 0 ; j < 3;j++){
                    if(num[j] < n / 3){
                        cout << j << endl;
                        if(str[i] - '0' > j && sum[str[i] - '0'] == 0){
                            cout << j;
                            sum[j]++;
                            num[j]++;
                            break;
                        }else if(str[i] - '0' < j && sum[str[i] - '0'] == n / 3){
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
            }else{
                sum[str[i] - '0']++;
                cout << str[i];
            }
        }
    }
}