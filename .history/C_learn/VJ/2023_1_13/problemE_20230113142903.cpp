#include <iostream>
#include <random>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], ans = 0;
// void partition(int arr[], int L, int R , int mid) {
//     int l = L;
//     int R = mid + 1;
//     int k = L;
//     while(j <= mid )
//     arr[less] = temp;
// }
// void quickSort(int arr[], int L, int R) {
//     if (L < R) {
//         int mid = (L + R) >> 1;
//         quickSort(arr, L, mid);
//         quickSort(arr, mid + 1, R);
//     }
// }
void merge(int arr[], int L, int M, int R) {
    int *help = new int[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        if (arr[p1] <= arr[p2]) {
            help[i++] = arr[p1++];
        } else {
            help[i++] = arr[p2++];
            ans += M - p1 + 1;
        }
    }
    while (p1 <= M) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }
    for (int i = 0; i < R - L + 1; i++) {
        arr[L + i] = help[i];
    }
}
void process(int arr[], int L, int R) {
    if (L == R) return;
    int mid = L + ((R - L) >> 1);
    process(arr, L, mid);
    process(arr, mid + 1, R);
    merge(arr, L, mid, R);
}
int main() {
    while (cin >> n, n != 0) {
        ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        // quickSort(a, 1, n);
        process(a, 1, n);
        // for (int i = 0; i < n; i++) cout << a[i] << endl;
        cout << ans << endl;
    }
}