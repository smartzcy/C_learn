#include<iostream>
using namespace std;
int gcd(int m,int n){
	int rem;
	while(n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;
}
int main(){
    long long n;
    cin >> n;
    int min = INT_MAX;
    int k = 0;
    for(int i = 1; i < n / 2;i++){
        int m = gcd(n - i , i);
        if((n - i) * i / m < min) {
            min = (n - i) * i / m;
            k = i;
        }
    }
    cout << k << " " << n - k;
}