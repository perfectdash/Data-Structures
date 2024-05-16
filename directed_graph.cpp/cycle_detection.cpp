#include <bits/stdc++.h>
using namespace std;



bool dfs(int src,map<int,bool>& visited,unordered_map<int,list<int>>& adj,bool* s){
    s[src]=true;
    visited[src]=true;
    
    for(auto i:adj[src]){
        if(!s[i]){
            dfs(i,visited,adj,s);
        }else{
            return true;
        }
    }
    
    s[src]=false;
    return false;
}


// bhai saaf si baat hai ek raaste pe apn log chal rahe hain aur 
// jaise hi raata change stack se entry bhi change par visited vaisa 
// hi rahega 

int main(){

    // int t;cin>>t;
    int t=1;
    while(t--){
        unordered_map<int,list<int>> adj;
        int n;cin>>n;int m;cin>>m;
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            adj[x].push_front(y);
        }
        bool *s = new bool[n+1];  
        map<int,bool> visited;
        bool ha_ki_na=false;

        cout<<dfs(1,visited,adj,s)<<"\n";
    }

    return 0;
}