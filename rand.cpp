#include <bits/stdc++.h>
using namespace std;
 

using ll = long long ;
using ld  = long double;
using u32 = unsigned int ;
using u64 = unsigned long long ;
using vl = vector<ll>;
using pl = pair<ll,ll>;
using vp = vector<pl>;

ll mod=1000000007;


#define f(i, a, b, c) for(ll i = a; i < b; i += c)
#define fd(i, a, b, c) for(ll i = a; i > b; i -= c)

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define all(a) a.begin(),a.end()
#define rev(a) a.rbegin(),a.rend()



void solve(){
    ll n,m,d; cin>>n>>m>>d ;ll x;ll flag= INT_MAX;
    vl a(n+1); f(i,0,n,1){cin>>x;a[x]=i+1;}
    vl b(m); f(i,0,m,1){cin>>x;b[i]=a[x];}
    if(d+1>=n){
        f(i,0,m-1,1){
          if(b[i]<b[i+1] and b[i+1]<=b[i]+d){
            flag= min(flag,b[i+1]-b[i]);
          }else{
            flag =0;
            break;
          }
        }
    }else{
        f(i,0,m-1,1){
          if(b[i]<b[i+1] and b[i+1]<=b[i]+d){
            ll ans = (b[i+1]-b[i]);
            ans = min(ans,b[i]+d-b[i+1]+1);
            flag= min(flag,ans);
          }else{
            flag =0;
            break;
          }
        }
    }
    
    cout<<flag<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<setprecision(12);

    u32 t=1;
    cin>>t;
    while(t--){
          solve();    
    }
    return 0;
    
}