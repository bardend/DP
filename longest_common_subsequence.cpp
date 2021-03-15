#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ss(s) scanf("%s",s)
#define str(x) strlen(x)
const int N=2520;
const int INF=1e9;
char a[N],b[N];
int dim[N],dp[N][N],rever[N][N];
void res(int n,int m){
	if(n<1 || m<1)return ;
	else {
		if(rever[n][m]==1){
			res(n-1,m-1);
			printf("%c",a[n-1]);
		}
		else if(rever[n][m]==2){
			res(n-1,m);
		}
		else 
			res(n,m-1);
	}
}
int main(){
	FAST;
	ss(a);
	ss(b);
	int n=str(a);
	int m=str(b);
	for(int i=1;i<=n;i++){
		int r=a[i-1]-'a';
		for(int j=1;j<=m;j++){
			int k=b[j-1]-'a';
			if(k==r){
				rever[i][j]=1;
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j]=dp[i-1][j];
					rever[i][j]=2;
				}
				else {
					dp[i][j]=dp[i][j-1];
					rever[i][j]=3;
				}
			}
		}
	}
	printf("The len of the max common subsequence is : %d\n",dp[n][m]);
	res(n,m);
	printf("\n");
	return 0;
}