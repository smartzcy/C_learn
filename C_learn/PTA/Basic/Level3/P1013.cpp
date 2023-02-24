#include<iostream>
#include<cstring>
using namespace std;
int num[1001];
void ways(){
    memset(num,1,sizeof(num));
    num[1] = 0;
    for(int i = 2 ; i <= 1000;i++)
        if(num[i])
            for(int j = i, k = 2;j * k <= 1000;k++)
                num[j * k] = 0;
}
int main(){
    ways();
    int n , m;
    cin >> n >> m;
    int count = 0;
    for(int i = 2; i <= 1000;i++){
        if(num[i]) {
            count++;
            if(count >= n && count <= m){
                cout << i;
                if((count - n + 1) % 10 == 0 || count == m) cout << endl;
                else cout << " ";
                if(count == m) break;
            }
        }
    }
}