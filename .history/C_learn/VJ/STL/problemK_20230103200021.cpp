#include<iostream>
#include<algorithm>
using namespace std;
int H[11][20] = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1},{1,6,15,20,15,6,1},{1,7,21,35,35,21,7,1},{1,8,28,56,70,56,28,8,1},{1,9,36,84,126,126,84,36,9,1},{1,10,45,120,210,252,210,120,45,10,1}};
int main(){
    int n , num , flag = 0;
    cin >> n >> num;
    int number[11];
    for(int i = 0 ; i < n; i++){
        number[i] = i + 1;
    }
    do{
        int sum = 0;
        for(int i = 0 ; i < n;i++){
            sum += number[i] * H[n - 1][i];
        }
        if(sum == num){
            for(int i = 0 ; i < n; i++){
                cout << number[i] << " ";
                flag = 1;
                break;
            }
        }
    }while(next_permutation(number , number + n));
    if(flag == 0) cout << "Not Found";
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