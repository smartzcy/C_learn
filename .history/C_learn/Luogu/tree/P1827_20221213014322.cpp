#include <iostream>
using namespace std;
void Print(string pre, string ino)
{
    if (pre.empty())
        return;
    char root = pre[0];
    int k = ino.find(root);
    pre.erase(pre.begin());
    string left1 = pre.substr(0, k);
    string right1 = pre.substr(k);
    string left2 = ino.substr(0, k);
    string right2 = ino.substr(k + 1);
    Print(left1, left2);
    Print(right1, right2);
    cout << root;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Print(s2, s1);
    return 0;
}