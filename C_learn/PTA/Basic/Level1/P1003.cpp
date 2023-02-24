// #include<iostream>
// #include<string.h>
// #include<string>
// using namespace std;
// int main(){
//     int T;
//     cin >> T;
//     getchar();
//     while(T--){
//         string str;
//         getline(cin,str);
//         int m = 0 , nm = 0;
//         for(int i = 0; i < str.length();i++){
//             if(str[i] != 'A' && str[i] != 'P' && str[i] != 'T' && str[i] != ' '){
//                 cout << "NO";
//                 break;
//             }else if(str[i] == 'P' && m == 0){
//                 int k = 0;
//                 int kong = 0;
//                 for(int j = i + 1; j < str.length();j++){
//                     if(str[j] == 'A') k++;
//                     else if(str[j] == ' ') kong++;
//                     else if(k == 0 && (str[j] == 'T' || str[j] == 'P') || k + kong >= 3){
//                         cout << "NO";
//                         m = 1;
//                         break;
//                     }else if(k +kong <= 2 && str[j] == 'T'){
//                         m = 2;
//                         i = j;
//                         break;
//                     }
//                 }
//             }else if((str[i] == 'P' || str[i] == 'T') && m == 2){
//                 nm = 1;
//                 cout << "NO";
//                 break;
//             }
//             if(m == 1) break;
//         }
//         if(m == 2 && nm == 0) cout << "YES";
//         if(T != 0) cout << endl;
//     }
// }
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        int lp , lt ,cp = 0 , ct = 0 , err = 0;
        for(int i = 0 ; i < str.length();i++){
            if(str[i] == 'P'){
                cp++;
                lp = i;
            }else if(str[i] == 'T'){
                ct++;
                lt = i;
            }else if(str[i] != 'A') err++;
        }
        if(err != 0 || ct != 1 || cp != 1 || lt - lp <= 1) cout << "NO" << endl;
        else {
            if(lp * (lt - lp - 1) == str.length() - lt - 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}