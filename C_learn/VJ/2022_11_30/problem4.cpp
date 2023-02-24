#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long x, long long y){
	long long z = y;
	while(x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}
int main(){
    int N;
    cin >> N;
    long long sum = 0;
    long long max1 = 0;
    for(int i = 0 ; i < N;i++){
        long long num;
        cin >> num;
        if(sum == 0){
            max1 = num;
            sum = num;
        }else{
            sum += num;
            max1 = sum * max1 / gcd(max(sum , max1) , min(sum , max1));
        }
    }
    cout << max1;
}