#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
const int N=2520;
const int INF=1e9;
int dim[N],dp[N][N],rever[N][N];
void res(int lo,int hi){
	if(lo==hi)
		cout<<"A"<<lo;
	else {
		cout<<"(";
		res(lo,rever[lo][hi]);
		res(rever[lo][hi]+1,hi);
		cout<<")";
	}
}
int main(){
	FAST;
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
		cin>>dim[i];
	
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	
	for(int k=2;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			int j=k+i-1;
			dp[i][j]=INF;
			for(int r=i;r<j;r++){
				int val=dp[i][r]+dp[r+1][j]+(dim[i-1]*dim[r]*dim[j]);
				if(val<dp[i][j]){
					dp[i][j]=val;
					rever[i][j]=r;
				}
			}
		}
	}
	cout<<"The min val is : "<<dp[1][n]<<'\n';
	res(1,n);
	cout<<'\n';
	return 0;
}