#include <bits/stdc++.h>
using namespace std;
 


void solve(){
    int n;cin>>n; vector<int>v(8,0);int x;
    for(int i=0;i<n;i++){
        cin>>x;v[x]++;
    }
    priority_queue<int> a,b,c;
    a.push(1);b.push(1);c.push(1);
    for(int i=0;i<n;i++){
        if(v[i]>(n/3)){
            cout<<-1<<"\n";
            return;
        }else{
           int y,z;
           x=a.top();
           y=b.top();
           z=c.top();
           if(i%x==0 and a.size()<n/3+1){
              a.push(i);
           }else if(i%y==0 and b.size()<n/3+1){

           }else if(i%z==0 and c.size()<n/3+1){

           }else{
               
           }
        }
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
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}