#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n , d , m = 1;
    while(cin >> n >> d , n != 0 && d != 0){
        int flag = 0;
        pair<double , double> ship[2010];
        for(int i = 0 ; i < n ;i++){
            double x , y;
            cin >> x >> y;
            if(y > d) flag = 1;
            double k = sqrt(d * d * 1.0 - y * y * 1.0);
            ship[i].first = x - k;
            ship[i].second = x + k;
        }
        if(flag == 1){
            cout << "Case " << m << ": -1" << endl;
        }else{
            sort(ship , ship + n);
            int ans = 0 ;
            double p = -2e9;
            for(int i = 0 ; i < n ;i++){
                if(ship[i].first > p){
                    ans++;
                    p = ship[i].second;
                }else if(ship[i].second < p){
                    p = ship[i].second;
                }
            }
            cout << "Case " << m << ": " << ans << endl;
        }
        m++;
    }
}