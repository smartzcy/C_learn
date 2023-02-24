#include <iostream>
#include <set>
using namespace std;
int main(){
    int n , sum = 0 , ans = 0;
    cin >> n;
    set<int> set1;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        sum += num;
        if(set1.find(sum) != set1.end() || sum == 0){
            ans++;
        }
        set1.insert(sum);
    }
}