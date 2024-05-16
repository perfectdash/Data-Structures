#include <bits/stdc++.h>
using namespace std;


void dfs(int src,map<int,bool>& visited,unordered_map<int,list<int>>& adj,list<int>& l){
    visited[src]=true;
    for(auto i:adj[src]){
        if(!visited[i]){
            dfs(i,visited,adj,l);
        }
    }
    l.push_front(src);
}


// topological sorting is only defined for DAGS
// if we are enable to find a valid topo means 
// graph is cyclic;



// bhai baat seedhi si hai question aaye bhi toh dfs se hi krna hai 

int main(){

    // int t;cin>>t;
    int t=1;
    while(t--){
        unordered_map<int,list<int>> adj;
        int n;cin>>n;int m;cin>>m;
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            x--;y--;
            adj[x].push_front(y);
        }
        map<int,bool> visited;
        list<int> l; 
        // shit yaar source node me random kisi ko bhi bana dia hai 
        // iska matlab ki kisi ko bhi src le shkta hu main 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,l);
            }
        }


        queue<int> q;
        vector<int> indegree(n);
        // bfs me hum aise hi kahi se start nahi kar shkte hai 
        // hame indegree 0 wale node se start karna hota hai 


        // adj list me jaakar indegree nikal raha hu 
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        } 
        
        // indegree 0 walo ko daal raha hu 
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
               q.push(i);
            }
        }
        
        // bhai bas sara game indegree ka hai indegree o hogyi fir
        // daalo do aur usko baad jab uski baari aaye to nikal do 
        // indegree o matlab ki list ke 


        while(!q.empty()){
            int frn = q.front();
            l.push_front(frn);
            q.pop();
            for(auto j: adj[frn]){
                indegree[j]--;
                if(indegree[j]==0){
                   q.push(j);
                }
            }
        }


        for(auto i: l){
            cout<<i+1<<" ";
        }
        cout<<"\n";

    }

    return 0;
}