#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int result = 0;
        double hp1 , hp2 , a1 , a2 , b1 , b2 , tp;
        cin >> hp1 >> a1 >> b1;
        cin >> hp2 >> a2 >> b2 >> tp;
        double hp_dun = hp2 * 0.5 + 1000;
        double hp = hp2;
        double dang1 = b1 >= 95 ? 0.05 : (100 - b1) / 100;
        double dang2 = b2 >= 95 ? 0.05 : (100 - b2) / 100;
        int n;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            int x , y;
            cin >> x >> y;
            switch (x){
                case 0:
                    if(hp_dun > 0) hp_dun -= a1 * dang2;
                    else hp2 -= a1 * dang2;
                    break;
                case 1:
                    if(hp_dun > 0){
                        if(tp == 0) hp_dun -= a1 * dang2 * 1.5 * 3;
                        else if(tp == 2) hp_dun -= hp_dun -= a1 * dang2 * 0.5;
                    }else hp2 -= a1 * dang2 * 1.5;
                    break;
                case 2:
                    if(hp_dun > 0){
                        if(tp == 1) hp_dun -= a1 * dang2 * 1.1 * 3;
                        else if(tp == 0) hp_dun -= hp_dun -= a1 * dang2 * 0.5;
                    }else hp2 -= a1 * dang2 * 1.1;
                    break;
                case 3:
                    if(hp_dun > 0){
                        if(tp == 2) hp_dun -= a1 * dang2 * 1.4 * 3;
                        else if(tp == 1) hp_dun -= hp_dun -= a1 * dang2 * 0.5;
                    }else hp2 -= a1 * dang2 * 1.4;
                    break;
                case 4:
                    a1 *= 1.2;
                    break;
            }
            if(hp2 <= 0 && result == 0) result = 2;
            switch (y){
                case 0:
                    hp1 -= 2 * a2 * dang1;
                    break;
                case 1:
                    hp1 -= 3 * a2;
                    break;
                case 2:
                    hp2 += hp * 0.2;
                    break;
            }
            if(hp1 <= 0 && result == 0)result = 1;
        }
        if(hp2 > 0 || result == 1) cout << "This junjun is xunla!";
        else cout << "junjun ni zhen bang!";
        if(T != 0) cout << endl;
    }
}