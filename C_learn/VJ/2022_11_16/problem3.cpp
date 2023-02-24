#include<iostream>
using namespace std;
int main(){
    long long Vk , Jk;
    cin >> Vk >> Jk;
    long long Va , Ja;
    cin >> Va >> Ja;
    long long Vh , Dh , Jh;
    cin >> Vh >> Dh >> Jh;
    cout << (Vk * Jk * Vh * Dh * Jh + Vh * Dh * Jh * Va * Ja);
}