#include <bits/stdc++.h>
using namespace std;



// An extension of dfs ----------------------------------------------------------------------->

using ll = long long ;
ll del_X[] = {-1,0,1,0};
ll del_Y[] = {0,-1,0,1};


// template <typename T>
void FLOOD_FILL_ALGORITHM(vector<vector<ll>>& A,ll i,ll j,ll x,ll y,ll n,ll m){
     // base condition 
     if(i>=n || i<0 || j<0 || j>=m){
        return;
     }
     // boundary conditoins 
     if(A[i][j]==x){
        return;
     }
    
     A[i][j]=y;
     
     // recursive call or fucking dfs 
      for(ll p=0;p<4;p++){
          FLOOD_FILL_ALGORITHM(A,i+del_X[p],j+del_Y[p],x,y,n,m);
      }
}





int main()
{

    vector<vector<ll>> v(3,vector<ll>(3,0)); 
    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    
    FLOOD_FILL_ALGORITHM(v,1,0,0,2,3,3);
    

    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
}