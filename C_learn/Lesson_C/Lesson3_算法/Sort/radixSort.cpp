#include <iostream>
#include <math.h>
using namespace std;
void radixSort(int arr[]){
    if (arr == NULL || sizeof(arr) / sizeof(*arr) < 2){
        return;
    }
    radixSort(arr, 0, sizeof(arr) / sizeof(*arr) - 1, maxbits(arr));
}
// 找最大值 看看最大值有几位
int maxbits(int arr[]){
    int max1 = INT_MIN;
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++){
        max1 = max(max1, arr[i]);
    }
    int res = 0;
    while (max1 != 0){
        res++;
        max1 /= 10;
    }
    return res;
}
void radixSort(int arr[], int L, int R, int digit){
    const int radix = 10;
    int i = 0, j = 0;
    // 有多少个数准备多少空间
    int *bucket = new int[R - L + 1];
    for (int d = 1; d <= digit; d++){ // 有多少位进出多少次
        // 10个空间
        // count[0] 当前位（d位）是0数字有多少个
        // count[1] 当前位（d位）是（0和1）的数字有多少个
        // count[2] 当前位（d位）是（0，1和2）的数字有多少个
        // count[i] 当前位（d位）是（0~i）的数字有多少个
        int *count = new int[radix];
        for (i = L; i <= R; i++){
            j = getDigit(arr[i], d);
            count[d]++;
        }
        // 记录每个数的量 然后根据这个（d位）的数字有几个 决定这个数在数组的什么位置，数量-1.
        for (i = 1; i < radix; i++){
            count[i] = count[i] + count[i - 1];
        }
        // 从后往前 向数组中添加 （模拟队列） 位置是（d位）的量 - 1
        for (i = R; i >= L; i--){
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (i = L, j = 0; i <= R; i++, j++){
            arr[i] = bucket[j];
        }
    }
}
int getDigit(int x, int d){
    return ((x / (int)pow(10,d - 1)) % 10);
}
int main(){
}