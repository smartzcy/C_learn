#include<iostream>
#include<string>
using namespace std;
int main(){
    string hai , xie;
    while (cin >> hai >> xie,hai != "0"){
        if(hai.length() < xie.length()){
            printf("No\n");
        }else {
            int n1 = 0 , n2 = 0;
            while (n1 < hai.length() && n2 < xie.length()){
                if(hai.substr(n1,1).c_str()[0] + xie.substr(n2,1).c_str()[0] == 155) n2++;
                n1++;
            }
            if(n2 == xie.length())printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}