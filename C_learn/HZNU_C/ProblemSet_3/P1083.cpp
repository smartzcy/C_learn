#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string str1[10] = {" _ ","   "," _ "," _ ","   "," _ "," _ "," _ "," _ "," _ "};
    string str2[10] = {"| |","  |"," _|"," _|","|_|","|_ ","|_ ","  |","|_|","|_|"};
    string str3[10] = {"|_|","  |","|_ "," _|","  |"," _|","|_|","  |","|_|"," _|"};
    int n1 , n2 , n3 , n4;
    while (~scanf("%d %d %d %d",&n1,&n2,&n3,&n4)){
        cout << str1[n1] << str1[n2] << str1[n3] << str1[n4] << endl;
        cout << str2[n1] << str2[n2] << str2[n3] << str2[n4] << endl;
        cout << str3[n1] << str3[n2] << str3[n3] << str3[n4] << endl;
    }
    return 0;
}