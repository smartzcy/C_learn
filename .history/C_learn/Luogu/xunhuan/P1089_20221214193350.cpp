#include<iostream>
using namespace std;
int main(){
    int now = 0;
    int cun = 0;
    for(int i = 0 ; i < 12;i++){
        now += 300;
        int num;
        cin >> num;
        if(now < 0) continue;
        
        if(now < num) now = -(i + 1);
        else now -= num;
        cout << num << " " << now << endl;
        cun += now / 100 *100;
        now %= 100;
    }
    if(now < 0) cout << now;
    else cout << now + 0.2 * cun;
}