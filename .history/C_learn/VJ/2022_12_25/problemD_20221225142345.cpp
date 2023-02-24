#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m = 0;
        cin >> n;
        cout << "0 ";
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            if(i == 0) m = 0 ^ num;
            else {
                cout << ((num | m) ^ num) << " ";
                m |= num;
            }
        }
        cout << endl;
    }
    return 0;
}