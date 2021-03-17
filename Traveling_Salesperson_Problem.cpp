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
vector<int>adj[N];
bool vis[N];
long long dist[N][N];
long long dfs(int u){
	vis[u]=1;
	int cont=0;
	long long ans=INF;
	for(auto p:adj[u]){
		if(!vis[p]){
			cont++;
			ans=min(ans,dfs(p)+dist[u][p]);
		}
	}
	if(cont==0){ // final of the path	
		vis[u]=0; 
		if(dist[u][1]==0) //en caso no puedas volver al inicio
			return INF;
		else
			return dist[u][1];	//you can return to node 1			
	}
	vis[u]=0; 
	return ans;
}
int main(){
	FAST;
	int n,m;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	//n nodes
	//m vertex
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		//a first node
		//b second node 
		//c vertex weight fron a to b (a--->b)
		adj[a].pb(b); 
		dist[a][b]=c;
	}
	for(int i=1;i<=n;i++)
		dist[i][i]=0;
	//node initial (1)
	cout<<dfs(1)<<'\n';
}