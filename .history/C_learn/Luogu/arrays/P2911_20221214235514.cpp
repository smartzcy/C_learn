#include <iostream>
using namespace std;
int main(){
    int num[81] = {0};
    int s1 , s2 , s3;
    cin >> s1 >> s2 >> s3;
    for(int i = 1 ; i <= s1 ;i++){
        for(int j = 1 ; j <= s2;j++){
            for(int k = 1 ; k <= s3;k++){
                num[i + j + k]++;
            }
        }
    }
    int max = 1;
    for(int i = 1 ; i <= 80;i++){
        if(num[i] > num[max]) max = num[i];
    }
    cout << max << endl;
}