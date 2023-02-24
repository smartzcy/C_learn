#include<iostream>
using namespace std;
int main(){
	int j = 1,x = 0,y = 0,N;
	char C;
	cin >> N >> C;
	while(2 * j * j - 1 <= N){
		j++;
	}
	j--;
	y = 2 * j - 1;
	while(y > 0){
		for(int i = 0 ; i < x ; i++)
			cout << " ";
		for(int i = 0 ;i < y ;i++)
			cout << C;
		cout << endl;
		x++; 
		y -= 2;
	}
	x--;
	y+=2;
	while(x > 0){
		x--;
		y += 2;
		for(int i = 0;i < x;i++)
			cout << " ";
		for(int i = 0;i < y;i++)
			cout << C;
		cout << endl;	
	}
	cout << N - 2 * j * j + 1 << endl;
	return 0;
}
