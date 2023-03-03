#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
struct node {
    string name;
    int num;
} seg[N];
int main() {
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> seg[i].name >> seg[i].num;
        sum += seg[i].num;
    }
    int mid = sum / n / 2, minn = 1e7, tag = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(mid - seg[i].num) < minn) {
            minn = abs(mid - seg[i].num);
            tag = i;
        }
    }
    cout << mid << " " << seg[tag].name << endl;
}