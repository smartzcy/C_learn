// #include<stdio.h>
// #include<string.h>
// #include<vector>
// #include<algorithm>
// #include<string>
// using namespace std;
// int main(){
//     char ch;
//     vector<string> vec;
//     int n = 0;
//     while (~scanf("%c",&ch)){
//         string str;
//         if(ch == '\n'){
//             n = 0;
//         }else if(ch == '('){
//             n = 1;
//             vector<string>::iterator iter = find(vec.begin(),vec.end(),str);
//             if(iter == vec.end()){
//                 vec.push_back(str);
//             }
//             str = "";
//         }else if(n == 0){
//             str.push_back(ch);
//         }
//     }
//     sort(vec.begin(),vec.end());
//     for(vector<string>::iterator t = vec.begin(); t != vec.end();t++){
//         printf("%s\n",*t);
//     }
// }
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    char ch;
    map<string,int> map1;
    int n = 0;
    string str = "";
    while (~scanf("%c",&ch)){
        if(ch == '\n'){
            n = 0;
            if(map1.find(str) == map1.end()) map1.insert(pair<string,int>(str,1));
            str = "";
        }else if(ch == '(' && n == 0)  n = 1;
        else if(n == 0) str.push_back(ch);
        
    }
    for(auto i : map1) cout << i.first << endl;
    return 0;
}