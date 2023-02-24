#include<iostream>
#include<set>
using namespace std;
int H[11][20] = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1},{1,6,15,20,15,6,1},{1,7,21,35,35,21,7,1},{1,8,28,56,70,56,28,8,1},{1,9,36,84,126,126,84,36,9,1},{1,10,45,120,210,252,210,120,45,10,1}};
int main(){
    int n , num , flag1 = 0;
    cin >> n >> num;
    int k[11];
    for(int i = 0 ; i < n;i++){
        k[i] = 1;
    }
    while(k[0] != num){
        int sum = 0;
        for(int i = 0 ; i < n;i++){
            sum += H[n - 1][i] * k[i];
        }
        int m = 0;
        if(sum == num){
            int flag = 1;
            multiset<int> s;
            for(int i = 0 ; i < n;i++){
                if(s.find(k[i]) != s.end()) {
                    flag = 0;
                    break;
                }
                s.insert(k[i]);
            }
            if(flag == 1) {
                flag1 = 1;
                break;
            }
        }else if(sum > num){
            k[n - 1] = 1;
            m = n - 2;
        }else {
            m = n - 1;
        }
        k[m]++;
        while(k[m] == num){
            k[m] = 1;
            k[m - 1]++;
        }
    }
    if(flag1 = 1){
        for(int i = 0 ; i < n;i++){
            cout << k[i] << " ";
        }
    }else cout << "-1";
}
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1
1 8 28 56 70 56 28 8 1
1 9 36 84 126 126 84 36 9 1
1 10 45 120 210 252 210 120 45 10 1
*/