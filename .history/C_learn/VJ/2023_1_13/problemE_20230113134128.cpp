#include <iostream>
#include <random>
using namespace std;
const int N = 1e6;
int n, a[N], ans = 0;
// 处理arr[1...r]函数
// 默认以arr[r]做划分，arr[r] -> p   <p ==p >p
// 返回等于区域（左边界，右边界），所以返回一个长度为2的数组
int partition(int arr[], int L, int R) {
    int less = L;
    int more = R;
    int temp = arr[L];
    while (less < more) {
        while ((less < more) && (arr[more] >= temp)) more--;
        if (less < more) arr[less++] = arr[more];
        while ((less < more) && arr[less] < temp) less++;
        if (less < more) arr[more--] = arr[less];
    }
    arr[less] = temp;
    return less;
}
void quickSort(int arr[], int L, int R) {
    if (L < R) {
        int mid = partition(arr, L, R);
        quickSort(arr, L, mid - 1);
        quickSort(arr, mid + 1, R);
    }
}
int main() {
    while (cin >> n, n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        quickSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) cout << a[i] << endl;
    }
}