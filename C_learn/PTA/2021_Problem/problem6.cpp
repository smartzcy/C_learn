#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int m , n ,k;
    bool deng[100001] = {0};
    deng[1] = 1;
    cin >> m >> n >> k;
    for(int i = 2; i <= n;i++){
        int j = 1;
        while(pow(i,j) < m){
            deng[(int)pow(i,j)] = 1;
            j++;
        }
    }
    for(int i = 0 ; i < k;i++){
        int num;
        cin >> num;
        if(deng[num] == 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}