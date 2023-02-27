#include<iostream>
using namespace std;
struct People{
    bool flag;
    string name;
}people[100000];
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> people[i].flag >> people[i].name;
    }
    int k = 0;
    for(int i = 0 ; i < m;i++){
        int a , s;
        cin >> a >> s;
        if(people[k].flag == 1){
            if(a == 1){
                k -= s;
            }else{
                k += s;
            }
        }else{
            if(a == 1){
                k += s;
            }else{
                k -= s;
            }
        }
        k = (k % n + n) % n;
    }
    cout << people[k].name;
}