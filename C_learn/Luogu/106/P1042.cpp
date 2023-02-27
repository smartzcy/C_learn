#include<iostream>
using namespace std;
int num[100000];
int main(){
    char ch;
    for(int i = 0 ; cin >> ch && ch != 'E';i++){
        if(ch == 'W') num[i] = 1;
        else num[i] = 2;
    }
    int w = 0 , l = 0;
    for(int i = 0 ; ;i++){
        if(num[i] == 1) w++;
        if(num[i] == 2) l++;
        if(num[i] == 0){
            cout << w << ":" << l << endl << endl;
            break;
        }
        if((w >= l + 2 || l >= w + 2) && (l >= 11 || w >= 11)){
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
    }
    w = 0 , l = 0;
    for(int i = 0 ;;i++){
        if(num[i] == 1) w++;
        if(num[i] == 2) l++;
        if(num[i] == 0){
            cout << w << ":" << l;
            break;
        }
        if((w >= l + 2 || l >= w + 2) && (l >= 21 || w >= 21)){
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
    }
    return 0;
}