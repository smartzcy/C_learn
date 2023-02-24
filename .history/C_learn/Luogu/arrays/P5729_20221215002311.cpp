#include <iostream>
using namespace std;
int main(){
    int num[21][21][21] = {{{1}}};
    int w , x , h , q;
    cin >> w >> x >> h;
    cin >> q;
    while(q--){
        int x1 , y1 , z1 , x2 , y2 , z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2;
        for(int i = x1 ; i <= x2 ; i++){
            for(int j = y1 ; j <= y2 ; j++){
                for(int k = z1 ; k <= z2 ; k++){
                    num[i][j][k] = 0;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 1 ; i <= w; i++){
        for(int j = 1 ; i <= x; i++){
            for(int k = 1 ; k <= h; k++){
                sum += num[i][j][k];
            }
        }
    }
    cout << sum << endl;
}