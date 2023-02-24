#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    int num[7] = {0};
    while(T--){
        int k = 0;
        for(int i = 1 ; i <= 4;i++){
            k *= 10;
            for(int j = 1 ; j <= 4;j++){
                char ch;
                cin >> ch;
                if(ch == '*'){
                    k = j + k;
                }
            }
            getchar();
        }
        if(k == 1111) num[0]++;
        else if(k == 2520) num[1]++;
        else if(k == 550) num[2]++;
        else if(k == 2310) num[3]++;
        else if(k == 2250) num[4]++;
        else if(k == 311) num[5]++;
        else if(k == 750) num[6]++;
    }
    for(int i = 0 ; i < 7;i++){
        if(i == 0) cout << num[i];
        else cout << " " << num[i];
    }
}