//https://usaco.guide/CPH.pdf#page=112
#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ss(s) scanf("%s",s)
#define str(x) strlen(x)
#define pb push_back
#define DBG(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define RAYA do {cerr << "===========================" << endl; } while (false)
//#define DBG do { } while(false);
//#define RAYA do { }while(false);
#define F(i,n) for(int i=0;i<n;i++)
#define ones(x) __builtin_popcount(x) //number of ones
const int MOD=1e9+7;
const int K=15;
const int mascara=1<<15;
const int N=100;
int v[N][K],dp[N][mascara];

int main(){
	FAST;
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>v[i][j];
		
	
	F(i,k)
		dp[0][1<<i]=v[i][0];
		
	for(int i=0;i<k-1;i++)
		for(int mask=0;mask<(1<<k);mask++)
			if(ones(mask)>i+1)
				dp[i][mask]=MOD;

	for(int i=1;i<n;i++){
		for(int mask=0;mask<(1<<k);mask++){
			dp[i][mask]=dp[i-1][mask];
			for(int j=0;j<k;j++){
				if(((1<<j)&mask)){
	dp[i][mask]=min(dp[i][mask],dp[i-1][mask^(1<<j)]+v[j][i]);
				}
			}
		}
	}
	cout<<dp[n-1][(1<<k)-1]<<'\n';
	return 0;
}
