#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n , d , m = 1;
    while(cin >> n >> d , n != 0 && d != 0){
        int flag = 0;
        pair<double , double> ship[2001];
        for(int i = 0 ; i < n ;i++){
            int x , y;
            cin >> x >> y;
            if(y > d) flag = 1;
            double k =  sqrt(d * d * 1.0 - y * y * 1.0);
            ship[i].first = (double)x - k;
            ship[i].second = (double)x + k;
        }
        if(flag == 1){
            cout << "Case " << m << ": -1\n";
        }else{
            sort(ship , ship + n);
            int ans = 0;
            for(int i = 0 ; i < n ;i++){

            }
        }
        m++;
    }
}