
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
	vector<st>v;
    	
	int binarySearch(int index){
		int lo=0;
		int hi=index-1;
		while(hi>lo){
			int mi=lo+(hi-lo+1)/2;
			if(v[mi].fin<v[index].ini){
				lo=mi;
			}	
			else hi=mi-1;			
		}
		if(v[lo].fin<v[index].ini)
			return lo;
			
		else return -1;
	}
    int main(){
		FAST;
    int n;
    cin>>n;
    //v.pb({0,0,0});
    for(int i=0;i<n;i++){
		int ini,fin,val;
		cin>>ini>>fin>>val;
		v.pb({ini,fin,val});	
	}	
    sort(v.begin(),v.end(),ria);
    
    dp[0]=v[0].val;
   
    for(int i=1;i<n;i++){
		dp[i]=v[i].val;
		int l=binarySearch(i);
		if(l!=-1)
			dp[i]+=dp[l];
			
		dp[i]=max(dp[i],dp[i-1]);	
	}

	cout<<dp[n-1]<<'\n';
	return 0;
    }
 
