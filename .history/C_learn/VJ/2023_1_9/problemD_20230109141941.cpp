#include<iostream>
#include<unordered_map>
using namespace std;
// int n , m , k , ans[100000] , vis[1001][1001] , temp = 0;
// string str[1001];
// int u[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
// void bfs(int x , int y){
//     vis[x][y] = temp;
//     for(int i = 0 ; i < 4;i++){
//         int xx = x + u[i][0];
//         int yy = y + u[i][1];
//         // cout << xx << " " << yy << endl;
//         if(xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0){
//             // cout << xx << " " << yy << endl;
//             if(str[xx][yy] == '*'){
//                 // cout << xx << " " << yy << endl;
//                 ans[temp]++;
//             }
//             if(str[xx][yy] == '.'){
//                 bfs(xx, yy);
//             }
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);
//     cin >> n >> m >> k;
//     for(int i = 0 ; i < n ; i++){
//         cin >> str[i];
//     }
//     for(int i = 0 , x , y ; i < k ; i++){
//         cin >> x >> y;
//         temp++;
//         if(!vis[x][y]){
//             bfs(x , y);
//         }
//         cout << ans[vis[x][y]] << endl;
//     }
// }

const int si=1006;//数组大小不解释

int n,m,k;
int tmp=0;
int ans[si*si];//这里ans数组用来存储答案，我的做法是用一维数组来储存，直接用pre数组的下标来访问，所以要开n^2的空间
int pre[si][si];//
char d[si][si];//地图，不解释
int dx[]={0,0,0,1,-1};
int dy[]={0,-1,1,0,0};//方向数组，不解释

void dfs(int x,int y){//深搜
	pre[x][y]=tmp;//tmp表示第tmp次询问（区分答案用的）
	for(register int i=1,nx,ny;i<=4;++i){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<1||ny<1||nx>n||ny>m){
			continue;
		}//边界，搜出去就continue掉
		if(pre[nx][ny]){
			continue;
		}//如果pre数组被修改过了（已经有答案储存在ans数组了），那也continue掉
		if(d[nx][ny]=='*'){
			ans[tmp]++;
		}//搜到*，计数器+（答案）+
		else{
			dfs(nx,ny);//继续递归搜索
		}
	}
}

int sx;
int sy;//开始的坐标。

int main(){
	cin>>n>>m>>k;
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=m;++j){
			cin>>d[i][j];
		}
	}
	for(register int i=1;i<=k;++i){
		cin>>sx>>sy;
		tmp++;//tmp只是一个区分答案的指针罢了
		if(!pre[sx][sy]){
			dfs(sx,sy);
		}//pre没有被修改过，也就是说它之前还没搜过，搜一遍。（如果之前搜过，那ans里一定会有答案，直接输出就好了）
		cout<<ans[pre[sx][sy]]<<endl;//输出
	}
	return 0;
}