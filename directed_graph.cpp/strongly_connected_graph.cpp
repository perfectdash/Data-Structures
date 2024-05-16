#include <bits/stdc++.h>
using namespace std;


void dfs(int src,vector<int>& visited,unordered_map<int,list<int>>& adj,vector<int>& order){
    visited[src]=1;
    for(auto i:adj[src]){
        if(!visited[i]){
            dfs(i,visited,adj,order);
        }
    }
    order.push_back(src);
}


void dfs_reverse(int src,vector<int>& visited,vector<int> component,unordered_map<int,list<int>>& adj){
    visited[src]=1;
    component.push_back(src);

    for(auto i: adj[src]){
        if(!visited[i]){
            dfs_reverse(i,visited,component,adj);
        }
    }

}

int main(){

    // int t;cin>>t;
    int t=1;
    while(t--){

        unordered_map<int,list<int>> adj,adj_1;
        int n;cin>>n;int m;cin>>m;
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            adj[x].push_front(y);
            adj_1[y].push_front(x);
        }
        vector<int> visited(n+1);
        vector<int> order;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,order);
            }
        }
        
        int count =0;
        memset(&visited,-1,sizeof visited);
        vector<vector<int>> component;
        for(int i =n;i>0;i--){
            if(!visited[order[i]]){
                vector<int> comp;
                dfs_reverse(order[i],visited,comp,adj);
                count++;
                component.push_back(comp);

            }
        }
        cout<<count<<"\n";
        for(auto i: component){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }

        
    }

    return 0;
}