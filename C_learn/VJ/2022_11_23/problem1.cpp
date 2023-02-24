#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    int flag = 0;
    int x = 0 , y = 0;
    while(T--){
        string a;
        cin >> a;
        if(a == "F"){
            int n;
            cin >> n;
            if(flag == 0){
                y += n;
            }else if(flag == 1){
                x += n;
            }else if(flag == 2){
                y -= n;
            }else if(flag == 3){
                x -= n;
            }
        }
        else if(a == "R") flag++;
        else if(a == "L") flag--;
        if(flag < 0) flag += 4;
        if(flag > 3) flag -= 4;
    }
    cout << x << " " << y << endl;
}