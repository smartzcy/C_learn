#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int x1 , x2 , x3 , y1 , y2 , y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int minx = min(x1 , min(x2 , x3)) , miny = min(y1 , min(y2 , y3));
        int maxx = max(x1 , max(x2 , x3)) , maxy = max(y1 , max(y2 , y3));
        if((x1 + x2 + x3 - minx - maxx) < maxx && (x1 + x2 + x3 - minx - maxx) > minx || (y1 + y2 + y3 - miny - maxy) > miny && (y1 + y2 + y3 - miny - maxy) < maxy) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}