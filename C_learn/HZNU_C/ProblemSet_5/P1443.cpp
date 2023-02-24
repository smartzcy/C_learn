#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n;
    int number = 1;
    while (cin >> n , n != 0){
        int num[333][333] = {{0}};
        int Max_H = 0;
        int Max_L = 0;
        cout << "Case " << number++ << ":" << endl;
        for(int i = 0 ; i < n ; i++){
            int x , y;
            string str;
            cin >> str >> x >> y;
            if(str == "add"){
                Max_H = Max_H > x ? Max_H : x;
                Max_L = Max_L > y ? Max_L : y;
                num[x][y] = 1;
            }else if(str == "remove"){
                num[x][y] = 0;
            }else if(str == "find"){
                if(x == Max_H || y == Max_L){
                    cout << "-1" << endl;
                }else{
                    int nm = 0;
                    for(int j = x + 1; j <= Max_H;++j){
                        for(int k = y + 1; k <= Max_L;++k){
                            if(num[j][k] == 1){
                                cout << j << " " << k << endl;
                                nm = 1;
                                break;
                            }
                        }
                        if(nm) break;
                    }
                    if(nm == 0){
                        cout << "-1" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
