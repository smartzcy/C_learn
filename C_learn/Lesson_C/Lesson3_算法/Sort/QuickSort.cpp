#include<iostream>
#include<algorithm>
using namespace std;
//通过概率 时间复杂度为（n log n)
//最坏的情况为n^2
void QuickSort(int arr[]){

}
void quickSort(int arr[] , int L , int R){
    if(L < R){
        //等概率shd
        swap(arr[(int)(rand() * (R - L + 1))],arr[R]);
        int *p = new int[2];
        p = partition(arr,L,R);
        quickSort(arr,L,p[0] - 1);// < 区
        quickSort(arr,p[1] + 1,R);// > 区
    }
}
//处理arr[1...r]函数
//默认以arr[r]做划分，arr[r] -> p   <p ==p >p
//返回等于区域（左边界，右边界），所以返回一个长度为2的数组
int *partition(int arr[],int L,int R){
    int less = L - 1;// <区右边界
    int more = R;// >区左边界
    while(L < more){//L表示当前数的位置 arr[R] -> 划分值
        if(arr[L] < arr[R]) swap(arr[++less],arr[L++]); //当前数 < 划分值
        else if(arr[L] > arr[R]) swap(arr[--more],arr[L]);
        else L++;
    }
    swap(arr[more],arr[R]);
    return new int[2]{less + 1,more};
}
int main(){

}