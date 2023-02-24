#include<iostream>
#include<map>
using namespace std;
int num[200000];
int main(){
    int T;
    cin >> T;
    while(T--){
        map<int,int> map1;
        int n;
        int sum = 0 , sum1 = 0;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> num[i];
            sum += num[i];
        }
        int max = 0;
        int max_sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum1 += num[i];
            map1[sum1] = i;
            sum -= num[i];
            if(map1.find(sum) != map1.end()){
                if(max < sum){
                    max = sum;
                    max_sum = n - i + map1.find(sum)->second;;
                }
            }
        }
        cout << max_sum << endl;
    }
}