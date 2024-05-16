#include <bits/stdc++.h>
using namespace std;


void solve(){
   int n;cin>>n; vector<int> a(n);for(int i=0;i<n;i++){cin>>a[i];}
   int idx =1; int val =1;vector<int> fuck; vector<int> shit;
   while(idx<n){
      if(a[idx-1]==idx){
        
      }else if(a[idx-1]>idx){
         
      }else{
         fuck.push_back(idx);
         shit.push_back(a[idx-1]);
      }
      idx++;
   }
   int final =0;
   sort(shit.begin(),shit.end());
   for(int i=0;i<(int)fuck.size();i++){
       int ans = upper_bound(shit.begin(),shit.end(),fuck[i])-shit.begin();
       if(shit[ans-1]==fuck[i]){
           ans++;
       }
       int flag = (int)shit.size()-ans;
       final+=max(flag,0);
   }

   cout<<final<<"\n";

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