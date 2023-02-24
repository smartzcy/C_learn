#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        cout << "0 ";
        int n , m = 0;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            int num;
            cin >> num;
            if(i == 0) m = 0 ^ num;
            else {
                if(num & m == m) {
                    cout << "0 ";
                    m = num;
                }else{
                    cout << ((num | m) ^ num) << " ";
                    m |= num;
                }
            }
        }
        cout << endl;
    }
    return 0;
}