#include<iostream>
#include<algorithm>
using namespace std;
int getMax(int arr[]){
    return process(arr , 0 , sizeof(arr) / sizeof(*arr) - 1);
}
int process(int arr[], int L , int R){
    if(L == R) return arr[L];
    int mid = L + ((R - L) >> 1);
    int left = process(arr , L , mid);
    int right = process(arr , mid + 1 , R);
    return max(left , right);
}
int main(){

}