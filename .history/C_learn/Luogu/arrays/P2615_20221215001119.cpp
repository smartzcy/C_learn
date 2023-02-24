#include <iostream>
using namespace std;
int main(){
    int n , num[40][40] = {{0}};
    cin >> n;
    int i = 1 , j = n / 2 + 1;
    num[i][j] = 1;
    for(int k = 2 ; k <= n * n ;k++){
        if(i == 1 && j != n){
            i = n;
            j++;
        }else if(j == n && i != 1){
            j = 1;
            i--;
        }else if(i == 1 && j == n){
            i++;
        }else if(i != 1 && j != n){
            if(num[i - 1][j + 1] == 0){
                i--;
                j++;
            }else{
                i++;
            }
        }
        num[i][j] = k;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << num[i][j];
            if(j != n) cout << " ";
            else cout << endl;
        }
    }
}