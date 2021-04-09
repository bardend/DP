
#include<bits/stdc++.h>
    using namespace std;
    #define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define ll long long
    #define ss(s) scanf("%s",s)
    #define str(x) strlen(x)
    #define pb push_back
    //#define DBG(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
   //#define RAYA do {cerr << "===========================" << endl; } while (false)
    #define DBG do { } while(false);
    #define RAYA do { }while(false);
    const int N=2e5+5;
    ll dp[N];
    struct st{
		int ini,fin,val;};
	bool ria(const st &t1,const st &t2){
		return t1.fin<t2.fin;	
	}	
    int main(){
		FAST;
    int n;
    cin>>n;
    vector<st>v;
    //v.pb({0,0,0});
    for(int i=0;i<n;i++){
		int ini,fin,val;
		cin>>ini>>fin>>val;
		v.pb({ini,fin,val});	
	}	
    sort(v.begin(),v.end(),ria);
    RAYA;
    RAYA;
    
    dp[0]=v[0].val;
    DBG(dp[0]);
   
    for(int i=1;i<n;i++){
		dp[i]=v[i].val;
		for(int j=i-1;j>=0;j--){
			if(v[j].fin<v[i].ini){
				dp[i]=max(dp[i],dp[j]+v[i].val);
				break;
			}
		}
		if(dp[i-1]>=dp[i]){
				dp[i]=dp[i-1];
				v[i].fin=v[i-1].fin;
		}
		DBG(dp[i]);
		DBG(v[i].ini);
		DBG(v[i].fin);
	}
	ll ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,dp[i]);
 
	cout<<ans<<'\n';
    return 0;
    }
 
