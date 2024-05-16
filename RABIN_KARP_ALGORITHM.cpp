#include <bits/stdc++.h>
using namespace std;
 

using ll = long long ;
using ld  = long double;
using u32 = unsigned int ;
using u64 = unsigned long long ;
using vl = vector<ll>;
using pl = pair<ll,ll>;
using vp = vector<pl>;

const int mod=1000000007;
const int p = 31; 

#define f(i, a, b, c) for(ll i = a; i < b; i += c)

#define fd(i, a, b, c) for(ll i = a; i > b; i -= c)

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define all(a) a.begin(),a.end()

int power(int a,int b){
     int pow =1; 
     while(b>0){
        if(b&1){
           pow*=a;
           pow%=mod;
        }
        b=b>>1;
        a*=a;
        a%=p;
     }
     return pow; 
}

int inv (int a){
     return (power(a,p-2)%p);
}

int poly_hash_strings(string s){
    int p = 31 ;int n = (int)s.size();
    int p_power=1; int hash =0;
    for(int i=0;i<n;i++){
        hash+=(p_power*(s[i]-'a'+1));
        p_power*=p;
        p%=mod;
        hash%=mod;
    }
    return hash ;
}


void RABIN_KARP_ALGORITHM(string& txt,string& pat){ 
    int n = txt.size(); int m = pat.size(); 
    int txt_hash = poly_hash_strings(txt.substr(0,m)); 
    int pat_hash = poly_hash_strings(pat);
    if(txt_hash==pat_hash){
        cout<<0<<"\n";
    }
    ll cnt =0; 
    int new_hash  = txt_hash;
    for(int i=1;i+m<=n;i++){
        new_hash = (txt_hash-((txt[i-1]-'a'+1))+mod)%mod ; 
        new_hash*=inv(p);
        new_hash%=mod; 
        new_hash +=((txt[i+m-1]-'a'+1)*power(p,m-1));
        new_hash%=mod;
        txt_hash%=mod;
        if(txt_hash==pat_hash){
            cout<<i<<"\n";
            cnt++; 
        }
        txt_hash=new_hash; 
    }

    if(cnt==0){
        cout<<-1<<"\n";
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
    // cin>>t;
    while(t--){
        string x,y;cin>>x>>y;
        RABIN_KARP_ALGORITHM(x,y);
    }
    return 0;
    
}