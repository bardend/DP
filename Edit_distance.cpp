#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ss(s) scanf("%s",s)
#define str(x) strlen(x)
#define pb push_back
const int N=5000+5;
const long long INF=1e9;
const int MOD=1000007;
int dp[N][N][3];
char a[N],b[N];
int main(){
	FAST;
	int t;
t=1;
	while(t--){

	int n,m;
	ss(a);
	ss(b);
	n=str(a);
	m=str(b);
	for(int i=0;i<=max(n,m);i++)
		for(int k=0;k<3;k++){
		dp[i][0][k]=i;
		dp[0][i][k]=i;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x=a[i-1]-'a';
			int y=b[j-1]-'a';
			if(x==y){
				int r=min(dp[i-1][j-1][0],min(dp[i-1][j-1][1],dp[i-1][j-1][2]));
				for(int k=0;k<3;k++)
					dp[i][j][k]=r;
			}
			else {
				int r=min(dp[i-1][j][1],min(dp[i][j-1][1],dp[i-1][j-1][2]))+1;
				for(int k=0;k<3;k++)
					dp[i][j][k]=r;
		
			}

		}
	}
	cout<<min(dp[n][m][0],min(dp[n][m][1],dp[n][m][2]))<<'\n';

	}
}