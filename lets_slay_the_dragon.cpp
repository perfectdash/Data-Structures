#include <bits/stdc++.h>
using namespace std;
 


void solve(){
     int n;cin>>n; vector<int> a(n);long long  sum =0; for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
     int m ;cin>>m; int x,y;sort(a.begin(),a.end());
     for(int i=0;i<m;i++){
         cin>>x>>y;
         int l = lower_bound(a.begin(),a.end(),x)-a.begin();
         int idx  ;
         if(l==n){
            idx = n-1;
         }else{
            idx = l;
         }
         int p,q;int ans =0;int flag=0;
         if(idx>=1){
             p = max(0,x-a[idx]);
             q = max(0,x-a[idx-1]);
             if(p>q){
                ans+=q;
                if((y-sum+a[idx-1])>=0){
                    ans+=(y-sum+a[idx-1]);
                }
                
             }else{
                ans+=q;
                if((y-sum+a[idx])>=0){
                    ans+=(y-sum+a[idx]);
                }
        
             }
             
         }else{
            ans=max(0,a[idx]);
            if((y-sum+a[idx])>=0){
                ans+=y-sum+a[idx];
            }
         }

         cout<<ans<<"\n";

     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}