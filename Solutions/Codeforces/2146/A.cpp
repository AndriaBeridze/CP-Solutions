#include <bits/stdc++.h>
    
using namespace std;
int TC = 0;
    
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define size(v) (int) v.size()
#define left node * 2, l, (l + r) / 2
#define right node * 2 + 1, (l + r) / 2 + 1, r
#define inf (int) 1e18
    
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    
    vector<int> v;
    for (auto p : mp) {
        v.push_back(p.second);
    }
    
    sort(rall(v));
    int ans = 0;
    for (int i = 0; i < size(v); i++) {
        ans = max(ans, v[i] * (i + 1));
    }
    
    cout << ans << endl;
}
    
signed main(){
    int q = 1;
    cin >> q;
    while(++TC <= q) {
        solve();
    }
}