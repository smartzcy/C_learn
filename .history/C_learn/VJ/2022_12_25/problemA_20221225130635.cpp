#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int xa , ya , xb , yb , xf , yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        if(xa == xb){
            if(xf == xa && yf < max(yb , ya) && yf > min(yb , ya)){
                cout << 2 + abs(yb - ya) << endl;
            }else{
                cout << abs(yb - ya) << endl;
            }
        }else if(ya == yb){
            if(yf == ya && xf < max(xb , xa) && xf > min(xa , xb){
                cout << 2 + abs(xb - xa) << endl;
            }else{
                cout << abs(xb - xa) << endl;
            }
        }else{
            cout << abs(xb - xa) + abs(yb - ya) << endl;
        }
    }
    return 0;
}