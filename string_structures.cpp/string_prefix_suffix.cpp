#include <bits/stdc++.h>
using namespace std;

// returns the same string prefix and suffix of a string ;

string f(string s){
    int n = s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    string res[4];
    for(int i = 0; i < n; i += 1) if(i + d1[i] >= n){
        res[0] = s.substr(i - d1[i] + 1);
        break;
    }
    for(int i = 1; i < n; i += 1) if(i + d2[i] >= n){
        res[1] = s.substr(i - d2[i]);
        break;
    }
    for(int i = n - 1; i >= 0; i -= 1) if(i - d1[i] < 0){
        res[2] = s.substr(0, i + d1[i]);
        break;
    }
    for(int i = n - 1; i >= 1; i -= 1) if(i - d2[i] <= 0){
        res[3] = s.substr(0, i + d2[i]);
        break;
    }
    int i = 0;
    for(int j = 1; j < 4; j += 1) if(res[j].size() > res[i].size()) i = j;
    return res[i];
}


int main(){
   

   int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> f(n + 1);
    f[0] = n;
    while (f[1] + 1 < n && s[f[1]] == s[f[1] + 1]) {
        f[1]++;
    }
    for (int i = 2, j = 1, mx = 1 + f[1]; i < n; i++) {
        f[i] = std::max(0, std::min(mx - i, f[i - j]));
        while (f[i] + i < n && s[f[i]] == s[f[i] + i]) {
            f[i]++;
        }
    }
    int x = 1;
    // a^inf < b^inf <=> a+b < b+a
    for (int i = 2; i <= n; i++) {
        if (x + f[x] < i) {
            if (s[x + f[x]] < s[f[x]]) {
                x = i;
            }
        } else if (f[i - x] < x) {
            if (s[f[i - x]] < s[i - x + f[i - x]]) {
                x = i;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        std::cout << s[i % x];
    }














    return 0;
}