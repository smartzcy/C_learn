#include<iostream>
using namespace std;
int num[100000] , n , m;
void INIT(){
    for(int i = 1 ; i <= n ; i++) num[i] = i;
}
int find(int x){
    return x == num[x] ? x : num[x] = find(num[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    num[fx] = fy;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        INIT();
        for(int i = 0 ; i < m;i++){
            int x , y;
            cin >> x >> y;
            merge(y , x);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ;i++){
            cnt += i == num[i];
        }
        cout << cnt << endl;
    }
}