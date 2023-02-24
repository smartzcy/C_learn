#include <iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int num[4][2];
        string a , b;
        cin >> a >> b;
        for(int i = 0 ; i < 4 ;i++){
            num[i][0] = (a[i] - b[i] + 10) % 10;
            num[i][1] = (b[i] - a[i] + 10) % 10;
        }
        int now = 0;
        for(int i = 0 ; i < 4;i++){
            if(num[i][0] == 0 || num[i][1] == 0) continue;
            if(num[i][0] >= num[i][1]){
                now += num[i][1];
                for(int j = i + 1 ; j < 4;j++){
                    if(num[j][1] == 0) break;
                    if(num[j][0] < num[j][1]) break;
                    num[j][0] += min(num[j][1] , num[i][1]);
                    num[j][1] = max(0 , num[j][1] - num[i][1]);
                }
            }else {
                now += num[i][0];
                for(int j = i + 1 ; j < 4 ;j++){
                    if(num[j][0] == 0) break;
                    if(num[j][0] > num[j][1]) break;
                    num[j][1] += min(num[j][0] , num[i][0]);
                    num[j][0] = max(0 , num[j][0] - num[i][0]);
                }
            }
        }
        cout << now << endl;
    }
}