  //https://atcoder.jp/contests/dp/tasks/dp_g
    #include<bits/stdc++.h>
    using namespace std;
    #define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define ll long long
    #define ss(s) scanf("%s",s)
    #define str(x) strlen(x)
    #define pb push_back
    const int N=1e5+5;
    const int INF=1e9;
    int dp[N];
    vector<int>adj[N];
    int dfs(int u){
    	if(dp[u]!=-1)return dp[u];
    	if(adj[u].size()==0){
    		dp[u]=0;
    		return 0;
    	}
    	for(auto p:adj[u])
    		 dp[u]=max(1+dfs(p),dp[u]);
    	return dp[u];
    }
    int main(){
    	FAST;
    	int n,m;
    	cin>>n>>m;
    	for(int i=0;i<m;i++){
    		int a,b;
    		cin>>a>>b;
    		adj[a].pb(b);
    	}
    	memset(dp,-1,sizeof(dp));
    	int ans=0;
    	for(int i=1;i<=n;i++)
    		if(dp[i]==-1)
    			 ans=max(dfs(i),ans);
    	
    	cout<<ans<<'\n';
    	return 0;
    }