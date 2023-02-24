#include<iostream>
using namespace std;
const int N = 1e6 + 10;
long long t[N];
int n , q;
int lowbit(int x){
	return x & -x;
}
void add(int x , int val){
	while(x <= n){
		t[x] += val;
		x += lowbit(x);
	}
}
long long getsum(int x){
	long long sum = 0;
	while(x > 0){
		sum += t[x];
		x -= lowbit(x);
	}
	return sum;
}
void way(){
    
}
int main(){
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		int num;
		cin >> num;
		add(i , num);
	}
	for(int i = 1 ; i <= q ; i++){
		int k , u , v;
		cin >> k >> u >> v;
		if(k == 1){
			add(u , v);
		}else if(k == 2){
			cout << getsum(v) - getsum(u - 1) << endl;
		}
	}
}