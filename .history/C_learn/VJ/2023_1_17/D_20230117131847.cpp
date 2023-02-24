#include <iostream>
#include <deque>
using namespace std;
int n, m;
int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ":" << endl;
        deque<int> que;
        cin >> n >> m;
        while (m--) {
            string str;
            cin >> str;
            if (str == "pushLeft") {
                int x;
                cin >> x;
                if (que.size() == n) {
                    cout << "The queue is full" << endl;
                } else {
                    cout << "Pushed in left: " << x << endl;
                    que.push_front(x);
                }
            } else if (str == "pushRight") {
                int x;
                cin >> x;
                if (que.size() == n) {
                    cout << "The queue is full" << endl;
                } else {
                    cout << "Pushed in right: " << x << endl;
                    que.push_back(x);
                }
            } else if (str == "popLeft") {
                if (que.empty()) {
                    cout << "The queue is empty" << endl;
                } else {
                    cout << "Popped from left: " << que.front() << endl;
                    que.pop_front();
                }
            } else {
                if (que.empty()) {
                    cout << "The queue is empty" << endl;
                } else {
                    cout << "Popped from left: " << que.back() << endl;
                    que.pop_back();
                }
            }
        }
    }
}