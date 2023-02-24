#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int l1  = 0, l2 = 0;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        if(num == -1) l1++;
        if(num == 1) l2++;
    }
    if(l1 + 1 >= l2){
        while(l1 > 0 || l2 > 0){
            if(l2 > 0) {
                cout << "1 ";
                l2--;
            }
            if(l1 > 0) {
                cout << "-1 ";
                l1--;
            }
        }
    }else{
        int num = (l2 - l1 - 1) / (l1 + 1) + 1;
        int k = (l2 - l1 - 1) % (l1 + 1);
        while(l1 > 0){
            for(int i = 0 ; i < num;i++){
                cout << "1 ";
            }
            if(k > 0){
                cout << "1 ";
                k--;
            }
            if(l1 > 0) cout << "-1 ";
            l1--;
        }
        for(int i = 0 ; i < num;i++){
                cout << "1 ";
        }
    }
    return 0;
}