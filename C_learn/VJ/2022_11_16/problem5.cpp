// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     while(n--){
//         string str;
//         cin >> str;
//         int flag = 0;
//         if(str[0] == 'R'){
//             for(int i = 2 ; i < str.length() ; i++){
//                 if(str[i] == 'C') {
//                     flag = i;
//                     break;
//                 }
//             }
//             if(flag != 0){
//                 string n1 = str.substr(1,flag - 1);
//                 string n2 = str.substr(flag + 1,str.length());
//                 long long num1 = 0 , num2 = 0;
//                 for(int i = 0 ; i < n1.length() ; i++) num1 = num1 * 10 + (n1[i] - '0');
//                 for(int i = 0 ; i < n2.length() ; i++) num2 = num2 * 10 + (n2[i] - '0');
//                 if(num2 > 26) cout << (char)(num2 / 26 - 1 + 'A') << (char)(num2 % 26 - 1 + 'A') << num1 << endl;
//                 else cout << (char)(num2 - 1 + 'A') << num1 << endl;
//             }
//         }
//         if(flag == 0){
//             long long num1 = 0 , num2 = 0;
//             for(int i = 0 ; i < str.length() ; i++)
//                 if(str[i] >= '0' && str[i] <= '9') num1 = num1 * 10 + (str[i] - '0');
//                 else num2 = num2 * 26 + (str[i] - 'A' + 1);
//             cout << "R" << num1 << "C" << num2 << endl;
//         }
//     }
// }

// #include<iostream>
// #include<algorithm>
// #include<stdio.h>
// using namespace std;
// int main(){
//     string str;
//     int n;
//     cin >> n;
//     while(n--){
//         cin >> str;
//         int num1 , num2;
//         if(sscanf(str.c_str(),"R%dC%d",&num1,&num2) == 2){
//             cout << (char)(num2 / 26 - 1 + 'A') << (char)(num2 % 26 - 1 + 'A') << num1 << endl;
//         }else{
//             num2 = 0;
//             int i;
//             for(i = 0 ; isalpha(str[i]); i++){
//                 num2 *= 26;
//                 num2 += str[i] - 'A' + 1;
//             }
//             cout << "R" << str.c_str() + i << "C" << num2 << endl;
//         }
//     }
// }

// #include <iostream>
// using namespace std;
// bool isNum(char x)
// {
//     return x <= '9' && x >= '0';
// }
// string itos(string i)
// {
//     int temp = 0;
//     string res = "";
//     for (int k = 0; k < i.size(); k++)
//     {
//         temp = temp * 10 + i[k] - '0';
//     }

//     while (temp)
//     {
//         char t = (temp % 26) + 'A' - 1;
//         if (t == '@')
//             t = 'Z';
//         res = t + res;
//         temp = (temp - 1) / 26;
//     }
//     return res;
// }
// int Stoi(string s)
// {
//     int res = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         res = res * 26 + s[i] - 'A' + 1;
//     }
//     return res;
// }
// int main()
// {
//     int n;
//     string t;
//     scanf("%d", &n);
//     while (n--)
//     {
//         cin >> t;
//         int typ = 0, cst;
//         for (int i = 1; i < t.size(); i++)
//         {
//             if (t[i] == 'C' && isNum(t[i - 1]) && isNum(t[i + 1]))
//             {
//                 typ = 1;
//                 cst = i;
//                 break;
//             }
//         }
//         if (typ)
//         {
//             bool f = 0;
//             string ts = "", ts2 = "";
//             for (int i = 0; i < t.size(); i++)
//             {
//                 if (f)
//                     ts = ts + t[i];
//                 if (t[i] == 'C')
//                     f = 1;
//             }
//             for (int i = 1; i < t.size(); i++)
//             {
//                 if (t[i] == 'C')
//                     break;
//                 ts2 = ts2 + t[i];
//             }
//             cout << itos(ts) << ts2 << endl;
//         }
//         else
//         {
//             string ts = "", ts2 = "";
//             bool f = 0;
//             for (int i = 0; i < t.size(); i++)
//             {
//                 if (isNum(t[i]))
//                     f = 1;
//                 if (!f)
//                     ts = ts + t[i];
//                 else
//                     ts2 = ts2 + t[i];
//             }
//             cout << 'R' << ts2 << 'C' << Stoi(ts) << endl;
//         }
//     }
//     return 0;
// }

#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    long long n;
	cin>>n;
	while(n--){
        char q[1000000];
		cin>>q;
		long long  i=0,r=0,c=0;
		if (sscanf(q,"R%dC%d",&r,&c)==2){
			while (c){
                c--;
				q[i++]=c%26+'A';
				c/=26;
			}
			for (i--;i>=0;i--) cout<<q[i];
			cout<<r<<endl;
		}
		else{
			for (i=0;isalpha(q[i]);i++){
				c*=26;
				c+=q[i]-'A'+1;
			}
			printf("R%sC%d\n",q+i,c);
		}
	}
}
