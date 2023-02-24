#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num[] = {1,2,3,1};
    int ke[100001] = {0};
    int number[100001] = {0};
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m;i++){
        int a , b;
        cin >> a >> b;
        number[a] = b;
    }
    ke[1] = 1;
    for(int i = 1 ; i <= n ;i++)
        ke[number[i]] = num[ke[i] % 3];
    int a , b;
    cin >> a >> b;
    if(ke[a] == ke[b]) cout << "can I win the game?" << endl;
    else if(num[ke[a]] == ke[b]) cout << "wait for me, my dear!" << endl;
    else if(num[ke[b]] == ke[a]) cout << "change! change! change!" << endl;
    return 0;
}