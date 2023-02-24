#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    double x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        double x , y;
        cin >> x >> y;
        if(((x < min(x1 , x2) || x > max(x1 , x2)) && (y < min(y1 , y2) || y > max(y1 , y2))) || (y - y1) * (x - x2) != (y - y2) * (x - x1)){
            cout << "No" << endl;
        }else cout << "Yes" << endl;
    }
}