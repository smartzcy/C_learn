#include<iostream>
#include<algorithm>
using namespace std;
int num[10010];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int l = 1 , r = n;
        while(l < r){
            int mid = (l + r) >> 1 , cnt = 0;
            cout << "? " << l << " " << mid << endl;
            for(int i = l; i <= mid;i++){
                cin >> num[i];
                cnt += (num[i] >= l && num[i] <= mid);
            }
            if(cnt % 2 == 1) r = mid;
            else l = mid + 1;
        }
        cout << "! " << l << endl;
    }
}