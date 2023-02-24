#include<iostream>
using namespace std;
int star[11][101][101];
int main(){
    int n , q , c;
    cin >> n >> q >> c;
    for(int i = 0 ; i < n ; i++){
        int x , y , s;
        cin >> x >> y >> s;
        star[s][x][y]++;
    }
    for(int i = 0 ; i <= c;i++)
        for(int j = 1 ; j <= 100;j++)
            for(int k = 1 ; k <= 100 ;k++)
                star[i][j][k] += star[i][j - 1][k] + star[i][j][k - 1] - star[i][j - 1][k - 1];
    for(int i = 0 ; i < q ; i++){
        int t , x1 , y1 , x2 , y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int k = 0 ;k <= c ;k++){
            int val = (k + t) % (c + 1);
            sum += (star[k][x2][y2] + star[k][x1 - 1][y1 - 1] - star[k][x1 - 1][y2] - star[k][x2][y1 - 1]) * val;
        }
        cout << sum << endl;
    }
}