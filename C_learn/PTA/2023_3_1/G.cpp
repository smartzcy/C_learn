#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int Pa, Pb, a, b, c;
    cin >> Pa >> Pb >> a >> b >> c;
    if (Pa > Pb && !(a && b && c))
        cout << "The winner is a: " << Pa << " + " << (abs(a - 1) + abs(b - 1) + abs(c - 1)) << endl;
    else if (a && b && c)
        cout << "The winner is b: " << Pb << " + " << 3;
}