#include <bits/stdc++.h>
using namespace std;
 
using ll = long long ;

// spanning tree is a tree that connects the whole graph into a single component without cycles 
// minimum spanning tree is spanning tree with minimum coast and defined only for a undirected 
// edges 

class graph{
     ll V;
     list <pair<ll,ll>> l;
     public : 
     graph(ll V){
        this->V=V;
     } 

     void merge(ll u,ll v){
        l.push_back(make_pair(u,v));
     }

     ll leader(ll i,vector<ll>& parent){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]=leader(parent[i],parent);
     }
     
     void union_set(ll x,ll y,vector<ll>& parent){
         ll s1 = leader(x,parent);
         ll s2 = leader(y,parent);
         if(s1!=s2){
            parent[s2]=s1;
         }
     }
     
     bool cycle_detection(){
          vector<ll> parent(V);
          for(int i=0;i<V;i++){
             parent[i]=-1;
          } 
          for(auto i: l){
             ll x = leader(i.first,parent);
             ll y = leader(i.second,parent);
             if(x!=y){
                union_set(i.first,i.second,parent);
             }else{
                return true;
             }

          }
          parent.clear();
          return false;
        
     }
       
};



int main(){

   int t; cin>>t;
   while(t--){
      ll n;cin>>n; 
      graph p(n);ll flag=1;
      vector<int> cnt(n);
      for(int i=0;i<n;i++ ){
         int a,b;cin>>a>>b;
         a--; b--;
         p.merge(a,b);
         cnt[a]++; cnt[b]++; 
         if(cnt[a]>=3|| cnt[b]>=3){
            flag=0;
            
         }
      }
   }
}