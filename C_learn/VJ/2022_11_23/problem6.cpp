// #include<iostream>
// #include<string>
// #include<set>
// using namespace std;
// int main(){
//     set<string>set1;
//     string str , a1 , a2;
//     double a1 = 0 , aa = 0;
//a    int n1 = 0 , n2 = 0;
//     getline(cin,str);
//     getline(cin,a1);
//     getline(cin,a2);
//     while (str.find(" ") != string::npos) {
//         int found = str.find(" ");
//         set1.insert(str.substr(0, found));
//         str = str.substr(found + 1);
//     }
//     set1.insert(str);
//     while(a1.find(" ") != string::npos) {
//         int found = a1.find(" ");
//         if(set1.find(a1.substr(0, found)) != set1.end()) x1++;
//         n1++;
//         a1 = a1.substr(found + 1);
//     }
//     if(set1.find(a1) != set1.end()) x1++;
//     n1++;
//     while(a2.find(" ") != string::npos) {
//         int found = a2.find(" ");
//         if(set1.find(a2.substr(0, found)) != set1.end()) x2++;
//         n2++;
//         a2 = a2.substr(found + 1);
//     }
//     if(set1.find(a2) != set1.end()) x2++;
//     n2++;
//     if(x1 / n1 > x2 / n2) cout << "NUMBER TWO IS THE HUMAN";
//     else cout << "NUMBER ONE IS THE HUMAN";
// }

#include <iostream>
#include <set>
using namespace std;
int main(){
    set<string> set1;
    int a1 = 0 , a2 = 0 , n1 = 0 , n2 = 0;
    string str;
    while(true){
        cin >> str;
        set1.insert(str);
        char c = getchar();
        if(c == '\n') break;
    }
    while(true){
        cin >> str;
        if(set1.find(str) != set1.end()){
            a1++;
        }
        n1++;
        char c = getchar();
        if(c == '\n') break;
    }
    while(true){
        cin >> str;
        if(set1.find(str) != set1.end()){
            a2++;
        }
        n2++;
        char c = getchar();
        if(c == '\n') break;
    }
    if((double)a1 / n1 >= (double)a2 / n2) cout << "NUMBER TWO IS THE HUMAN";
    else cout << "NUMBER ONE IS THE HUMAN";
}