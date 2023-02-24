// #include<iostream>
// #include<stdio.h>
// #include<string.h>
// using namespace std;
// int main(){
//     char str[4][70];
//     string s[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
//     for(int i = 0 ; i < 4;i++)
//         cin >> str[i];
//     int len = strlen(str[0]) < strlen(str[1]) ? strlen(str[0]) : strlen(str[1]);
//     int k = 0;
//     for(int i = 0 ; i < len;i++){
//         if(str[0][i] == str[1][i]){
//             if(k == 0 && str[0][i] <= 'Z' && str[0][i] >= 'A'){
//                 k = 1;
//                 cout << s[str[0][i] - 'A'] << " ";
//             }else if(k == 1){
//                 if(str[0][i] <= '9' && str[0][i] >= '0') printf("%02d",str[0][i] - '0');
//                 else printf("%02d",str[0][i] - 'A' + 10);
//                 break;
//             }
//         }
//     }
//     len = strlen(str[2]) < strlen(str[3]) ? strlen(str[2]) : strlen(str[3]);
//     for(int i = 0 ; i < len;i++){
//         if(str[2][i] == str[3][i] && (str[2][i] <= 'Z' && str[2][i] >= 'A' || str[2][i] <= 'z' && str[2][i] >= 'a')){
//             printf(":%02d",i);
//             break;
//         }
//     }
// }
// #include<iostream>
// #include<stdio.h>
// #include<string.h>
// using namespace std;
// int main(){
//     string a1 , a2 , a3 , a4;
//     string s[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
//     cin >> a1 >> a2 >> a3 >> a4;
//     int k = 0;
//     for(int i = 0 ;i < a1.length() && i < a2.length();i++){
//         if(a1[i] == a2[i]){
//             if(k == 0 && a1[i] <= 'G' && a1[i] >= 'A'){
//                 k = 1;
//                 cout << s[a1[i] - 'A'] << " ";
//             }else if(k == 1){
//                 if(a1[i] <= '9' && a1[i] >= '0') printf("%02d",a1[i] - '0');
//                 else printf("%02d",a1[i] - 'A' + 10);
//                 break;
//             }
//         }
//     }
//     for(int i = 0 ; i < a3.length() && i < a4.length();i++){
//         if(a3[i] == a4[i] && (a3[i] <= 'Z' && a3[i] >= 'A' || a3[i] <= 'z' && a3[i] >= 'a')){
//             printf(":%02d",i);
//             break;
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>
int main(){
    int f = 1;
    char a[4][60];
    char b[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for (int i = 0; i < 4; i++){
        scanf("%s", a[i]);
    }
    int l = strlen(a[0]) < strlen(a[1]) ? strlen(a[0]) : strlen(a[1]);
    for (int i = 0; i < l; i++){
        if (a[1][i] == a[0][i] && a[1][i] >= 'A' && a[1][i] <= 'G' && f == 1){
            printf("%s ", b[a[1][i] - 'A']);
            f = 0;
            continue;
        }
        if (a[1][i] == a[0][i] && ((a[1][i] >= 'A' && a[1][i] <= 'N') || (a[1][i] >= '0' && a[1][i] <= '9')) && f == 0){
            int k;
            if (a[1][i] >= 'A' && a[1][i] <= 'N'){
                k = a[1][i] - 'A';
                printf("%d:", k + 10);
                break;
            }else{
                k = a[1][i] - '0';
                printf("0%d:", k);
                break;
            }
        }
    }
    l = strlen(a[2]) < strlen(a[3]) ? strlen(a[2]) : strlen(a[3]);
    for (int i = 0; i < l; i++){
        if (a[3][i] == a[2][i] && ((a[2][i] >= 'a' && a[2][i] <= 'z') || (a[2][i] >= 'A' && a[2][i] <= 'Z'))){
            if (i < 10)
                printf("0%d", i);
            else
                printf("%d", i);
            break;
        }
    }
}
