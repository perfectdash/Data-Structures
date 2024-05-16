// // O(n*n) 

// vector<int> z_trivial(string &s){
//     int n = s.size();
//     vector<int> z(n,0);
//     for(int i=1;i<n;i++){
//         while(z[i]+i<n and s[z[i]]==s[z[i]+i]){
//           z[i]++;
//         }
//     }
//     return z;
// }


// vector<int> z(string &s ){
//      int n= s.size(); 
//      int l=0;int r=0;
//      vector<int> z(n,0);
//      for(int i=0;i<n;i++){
//         if(r<i){
//            l=r=i;
//            while(r<n and s[r]==s[r-l]){
//                r++;
//            }
//            r--;
//            z[i]=(r-l+1);
//         }else{
//            int k=i-l; 
//            if(z[k]+i-1<r){
//               z[i]=z[k];
//            }else{
//               while(s[r-l]==s[r] and r<n){
//                 r++;
//               }
//               r--;
//               z[i]=(r-l+1);
//            }
//         }
//      }
//      return z;
// }
