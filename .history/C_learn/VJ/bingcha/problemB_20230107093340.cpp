#include<iostream>
using namespace std;
int n , m , num[1001];
void INIT(){
    for(int i = 1 ; i <= n ; i++) num[i] = i;
}
int find(int x){
    return num[x] == x ? x : num[x] = find(num[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    num[fx] = fy;
}
int main(){
    int n;
    while(cin >> n , n != 0){
        int m;
        cin >> m;
        INIT();
        for(int i = 0 ; i < m;i++){
            int x , y;
            cin >> x >> y;
            merge(y , x);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            cnt += num[i] == i;
            cout << num[i] << endl;
        }
        cout << cnt - 1 << endl;
    }
}