// #include<iostream>
// using namespace std;
// int main(){
//     string s = {"0123456789JQK"};
//     string s1 , s2 , s3;
//     cin >> s1 >> s2;
//     int i = 1;
//     while(i - 1 < s1.length() && i - 1 < s2.length()){
//         if(i % 2 == 1){
//             int num = (s1[s1.length() - i] - '0' + s2[s2.length() - i] - '0') % 13;
//             s3 += s[num];
//         }else{
//             int num = ((s2[s2.length() - i] - '0') - (s1[s1.length() - i] - '0') + 10) % 10;
//             s3 += (num + '0');
//         }
//         i++;
//     }
//     if(i - 1 != s1.length()) cout << s1.substr(0,s1.length() - i + 1);
//     else if(i - 1 != s2.length()) cout << s2.substr(0,s2.length() - i + 1);
//     for(int i = s3.length() - 1; i >= 0;i--){
//         cout << s3[i];
//     }
//     cout << endl;
//     return 0;
// }

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string A,B,result;
	cin>>A>>B;
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	if(A.length() <B.length())
		A+=string(B.length()-A.length(),'0');
	else if(A.length() > B.length())
		B+=string(A.length()-B.length(),'0');
	int len = B.length();
	for(int i=0;i !=len;i++){
		if(i%2 == 0){
			int temp = (A[i]+B[i]-'0'-'0')%13;
			if(temp ==10) result+='J';
			else if(temp == 11)  result+='Q';
			else if(temp == 12) result+='K';	
			else result+=temp+'0';
		}
		else
			result+=(B[i]-A[i]+10)%10+'0';
	}
	reverse(result.begin(),result.end());
	cout<<result;
}