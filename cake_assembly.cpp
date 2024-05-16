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


void solve(){
   ll n,w,h;cin>>n>>w>>h;ll x;
   vp cakes;
   vp choc;
   f(i,0,n,1){
     cin>>x;
     cakes.emplace_back(x-w,x+w);
    //  cakes[i]={x-w,x+w};
   }
   f(i,0,n,1){
     cin>>x;
     choc.emplace_back(x-h,x+h);
    //  choc[i]={x-h,x+h};
   }

   
   pl bound = {choc[0].ff-cakes[0].ff,choc[0].ss-cakes[0].ss};
   ll flag =0;ll flag1=0;
   f(i,0,n,1){
        if((cakes[i].ff+bound.ff)<=(choc[i].ff) && (cakes[i].ss+bound.ff)>=choc[i].ff){
             flag++;
        }
        if((cakes[i].ff+bound.ss)<=(choc[i].ff) && (cakes[i].ss+bound.ss)>=(choc[i].ff)){
             flag1++;
        }
    }
    
    if(flag1==(n-1) || flag==(n-1)){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }



    vl a(n); vl b(n); 
    f(i,0,n,1){cin>>a[i];}
    f(i,0,n,1){cin>>b[i];}
    ll flag=0;
    if(h>w){
     cout<<"NO"<<"\n";
      return;
    }
    f(i,1,n,1){
        if((a[i]-a[i-1]-2*h)<=(b[i]-b[i-1]-2*w)){
            flag++;
        }
    }
    if(flag!=(n-1)){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
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

    u32 t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}