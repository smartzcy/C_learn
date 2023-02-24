#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], ans = 0;
void merge(int arr[], int L, int M, int R) {
    int i = L;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        if (arr[p1] <= arr[p2]) {
            b[i++] = arr[p1++];
        } else {
            b[i++] = arr[p2++];
            ans += M - p1 + 1;
        }
    }
    while (p1 <= M)
        b[i++] = arr[p1++];
    while (p2 <= R)
        b[i++] = arr[p2++];
    for (int i = 0; i < R - L + 1; i++)
        arr[L + i] = b[i];
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
        process(a, 1, n);
        cout << ans << endl;
    }
}