#include<iostream>
#include<map>
using namespace std;
int num[200001] = {0};
int main(){
    map<int,int> map1;
    int flag = 0;
    int n , q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        map1[num[i]]++;
    }
    for(int i = 0 ; i < q;i++){
        int a , l , r , k;
        cin >> a >> l >> r >> k;
        if(a == 1){
            if(flag == 0){
                map1[num[l]]--;
                num[l] = r;
                map1[num[l]]++;
            }else{
                map1[num[l]]--;
                num[l] = r ^ k;
                map1[num[l]]++;
            }
        }else if(a == 2){
            int i = l;
            for(; i <= r;i++){
                if(map1[num[i]] * num[i] % k != 0){
                    break;
                }
            }
            if(i == r + 1){
                cout << "YES" << endl;
                flag = 1;
            }else{
                cout << "NO" << endl;
                flag = 0;
            }
        }
    }
}