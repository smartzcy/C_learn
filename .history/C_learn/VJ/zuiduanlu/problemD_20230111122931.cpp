#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int N = 1001;
pair<int,int> p[N];
double d[N][N];
int n , Sx , Sy , Tx , Ty , V1 , V2;
double f(int x1 , int y1 , int x2 , int y2){
    return sqrt((x2 - x1) * (x2 - x1) * 1.0 + (y2 - y1) * (y2 - y1) * 1.0);
}
double dij(){
    for(int i = 0 ; i <)
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        int a , b;
        cin >> a >> b;
        p[i] = {a , b};
    }
    cin >> Sx >> Sy >> Tx >> Ty;
    cin >> V1 >> V2;
    d[1][n + 1] = f(Sx, Sy, Tx, Ty) / (V1 * 1.0);
    for(int i = 1 ; i <= n ; i++){
        d[1][i] = f(Sx , Sy , p[i].first , p[i].second) / (V1 * 1.0);
    }
    for(int i = 1 ; i <= n ;i++){
        double k = (p[i].first , p[i].second , Tx , Ty);
        if(k / (V2 * 1.0) <= 3) d[i][n] = double(k / (V2 * 1.0));
        else d[i][n] = 3.0 + (k - V2 * 3.0) / (V1 * 1.0);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue;
            double k = (p[i].second , p[i].second , p[j].first , p[j].second);
            if(k / (V2 * 1.0) <= 3) d[i][j] = k / (V2 * 1.0);
            else d[i][j] = 3.0 + (k - V2 * 3.0) / (V1 * 1.0);
        }
    }

}