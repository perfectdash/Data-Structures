#include <bits/stdc++.h>
using namespace std;


int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    cout<<setprecision(12);

    int  t=1;
    cin>>t;
    while(t--){
        string s;cin>>s;
        map<int,int> m;
        for(int i=0;i<(int)s.size();i++){
          m[s[i]-'a']++;
        }
        int n=s.size();
        vector<char> ans(n);
        // int l=0;int r=n-1;int cnt =1;
        // for(auto i: m){
        //    int val = i.first;
        //    int it = i.second/2;
        //    while(l<r and it>0){
        //         ans[r]=ans[l]='a'+val;
        //         it--;l++;r--;
        //    }
        //    i.second=i.second%2;
        // }
        // for(auto i: m){
        //    int val = i.first;
        //    int it = i.second/2;
        //    if(i.second%2){
        //       if(cnt%2){
        //         ans[r]='a'+val;
        //         r--;
        //       }else{
        //         ans[l]='a'+val;
        //         l++;
        //       }
        //    }
        // }
        int l=0;int r=n-1;int cnt =1;

        
        for(int i=0;i<n;i++){
          cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
    
}