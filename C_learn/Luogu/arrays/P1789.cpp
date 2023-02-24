#include<iostream>
using namespace std;
int main(){
    int num[110][110] = {{0}};
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < m; i++){
        int x , y;
        cin >> x >> y;
        num[x + 1][y + 1] = 1;
        num[x][y + 1] = 1;
        num[x - 1][y + 1] = 1;
        num[x + 2][y + 1] = 1;
        num[x + 3][y + 1] = 1;
        num[x][y] = 1;
        num[x][y + 2] = 1;
        num[x + 2][y] = 1;
        num[x + 2][y + 2] = 1;
        num[x + 1][y] = 1;
        num[x + 1][y - 1] = 1;
        num[x + 1][y + 2] = 1;
        num[x + 1][y + 3] = 1;
    }
    for(int i = 0 ; i < k;i++){
        int x , y;
        cin >> x >> y;
        for(int j = 0 ; j < 5;j++){
            for(int k = 0 ; k < 5; k++){
                num[x - 1 + j][y - 1 + k] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 2 ; i <= n + 1;i++){
        for(int j = 2 ; j <= n + 1; j++){
            if(num[i][j] == 0) sum++;
        }
    }
    cout << sum;
}