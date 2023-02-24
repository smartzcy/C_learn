#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int count1 = 0 , count2 = 0;
    while(N--){
        int han1 , han2 , hua1 , hua2;
        cin >> han1 >> hua1 >> han2 >> hua2;
        if(han1 + han2 == hua1 && han1 + han2 != hua2) count2++;
        if(han1 + han2 != hua1 && han1 + han2 == hua2) count1++;
    }
    cout << count1 << " " << count2 << endl;
}