#include <bits/stdc++.h>
using namespace std;
 

using ll = long long ;
using i128 = __int128;
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



class graph{
        
        unordered_map<ll,list<ll>> adj;
        
        public:
         void addEdge(ll u,ll v,bool direction=true){
            // if bool is true then it will be an directed graph 
            adj[u].pb(v);
            if(!direction){
                adj[v].pb(u);
            }

         }

         void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<"-->";
                for(auto j:i.second){
                    cout<<j<<", ";
                }
                cout<<"\n";
            }
         }

         
         



};

void solve(){
    // n is vertex and m is no of edges 
    graph g ;ll n;cin>>n;ll m;cin>>m;f(i,0,m,1){ll u,v;cin>>u>>v;g.addEdge(u,v);}
    g.printAdjList();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    u32 t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}