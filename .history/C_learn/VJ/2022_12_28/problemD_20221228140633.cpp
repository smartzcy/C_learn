#include<iostream>
#include<map>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , a[200001] , max = 1;
        map<int , int> map1;
        a[0] = 1;
        cin >> n;
        int x = n , y = 0;
        for(int i = 1 ; i <= n;i++){
            cin >> a[i];
            a[i] = a[i] * a[i - 1];
            if(a[i] > 0 && map1.size() > 1){
                map<int,int>::iterator it = map1.upper_bound(0);
                if(a[i] / it->first > max){
                    max = a[i] / it->first;
                    x = it->second + 1;
                    y = n - i;
                }else if(it == map1.end()){
                    if(a[i] > max){
                        max = a[i];
                        x = 0;
                        y - n - i;
                    }
                }
            }else if(a[i] < 0 && map1.size() > 1){
                map<int , int>::iterator it = map1.lower_bound(0);
                it--;
                if(a[i] / it->first > max){
                    max = a[i] / it->first;
                    x = it->second + 1;
                    y = n - i;
                }
            }
            map1[a[i]] = i;
        }
        cout << x << " " << y << endl;
    }
}