#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long

#define ss(s) scanf("%s",s)
#define str(x) strlen(x)
const int N=2520;
const int INF=1e9;
int dim[N],dp[N][N],rever[N][N];
char a[N],b[N];
int n;
void sol(int lo,int hi){
	if(lo>hi)return;
	else if(lo==hi){cout<<a[lo-1];return;}
	else{
		if(rever[lo][hi]==1){
			cout<<a[lo-1];
			sol(lo+1,hi-1);
			cout<<a[lo-1];
		}
		else if(rever[lo][hi]==2){
			sol(lo+1,hi);
		}
		else{
			sol(lo,hi-1);
		}
	}
}
int main(){
	FAST;
	ss(a);
	n=str(a);
	
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int k=1;k<n;k++){
		for(int i=1;i<=n-k;i++){
			int j=i+k;
			if(a[i-1]==a[j-1]){				
				dp[i][j]=2+dp[i+1][j-1];
				rever[i][j]=1;

			}
			else if(dp[i+1][j]>dp[i][j-1]){
				rever[i][j]=2;
				dp[i][j]=dp[i+1][j];
			}
			else{
				rever[i][j]=3;
				dp[i][j]=dp[i][j-1];	
			}
		}
	}
	cout<<"MAX LEN IS : "<<dp[1][n]<<'\n';
	sol(1,n);
	cout<<'\n';
	return 0;
}