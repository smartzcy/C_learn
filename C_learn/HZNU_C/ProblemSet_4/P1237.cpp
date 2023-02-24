// #include<iostream>
// using namespace std;
// int main(){
//     int T;
//     cin >> T;
//     while (T--){
//         int n , m;
//         cin >> n >> m;
//         int direction = m - n;
//         int count = 1;
//         int i = 1 , j = 2;
//         while(1){
//             if(direction == 1) break;
//             if(i * 2 == direction || direction - i * 2 + (j - 1) < j - 1){
//                 count *= 2;
//                 break;
//             }else if(i * 2 > direction){
//                 count = count * 2 - 1;
//                 break;
//             }else if(i * 2 + j >= direction){
//                 count = count * 2 + 1;
//                 break;
//             }else{
//                 count++;
//                 i += j;
//                 j++;
//             }
//         }
//         cout << count << endl;
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
int main() {
	int n;
	long long x, y;
	long long step;
	int i, d;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		step = y - x;
		if (step == 2) {
			printf("2\n");
		} else {
			int l = 0;
			int i;
			for (i = l; i + l < step; i++) {
				l += i / 2;
			}
			printf("%d\n", i);
		}
	}
	return 0;
}