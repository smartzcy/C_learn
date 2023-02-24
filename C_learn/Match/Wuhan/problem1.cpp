#include<iostream>
using namespace std;
int main(){
    char num[101][101];
    int n , m , x , y;
    cin >> n >> m >> x >> y;
    for(int i = 1 ; i <= n ; i++){
        getchar();
        for(int j = 1 ; j <= m ; j++){
            cin >> num[i][j];
        }
    }
    int sum = 0;
    int flag;
    if(num[x][y] == 'D') flag = 1;
    if(num[x][y] == 'U') flag = 2;
    if(num[x][y] == 'L') flag = 3;
    if(num[x][y] == 'R') flag = 4;
    while(true){
        if(num[x][y] == 'D'){
            if(flag != 1) sum++;
            num[x][y] = '0';
            x++;
            flag = 1;
        }else if(num[x][y] == 'U') {
            if(flag != 2) sum++;
            num[x][y] = '0';
            x--;
            flag = 2;
        }else if(num[x][y] == 'L'){
            if(flag != 3) sum++;
            num[x][y] = '0';
            y--;
            flag = 3;
        }else if(num[x][y] == 'R'){
            if(flag != 4) sum++;
            num[x][y] = '0';
            y++;
            flag = 4;
        }else if(num[x][y] == '0'){
            if(flag == 1) x++;
            else if(flag == 2) x--;
            else if(flag == 3) y--;
            else if(flag == 4) y++;
        }
        if(x > n || y > m || x < 1 || y < 1) break;
    }
    cout << sum;
}