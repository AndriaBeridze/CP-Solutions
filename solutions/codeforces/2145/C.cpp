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

int calc(string s) {
    int n = size(s);
    int a[n];

    for (int i = 0; i < n; i++) a[i] = (s[i] == 'a' ? 1 : -1) + (i ? a[i - 1] : 0);

    if (a[n - 1] == 0) return 0;

    map<int, int> mp;
    mp[0] = -1;
    int ans = n;
    for (int i = 0; i < n; i++) {
        int val = a[i] - a[n - 1];
        if (mp.find(val) != mp.end()) {
            // cout << i << ' ' << mp[val] << endl;
            ans = min(ans, i - mp[val]);
        }

        mp[a[i]] = i;
    }

    return ans;
}
    
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = calc(s);
    cout << (ans == n ? -1 : ans) << endl;
}
    
signed main(){
    int q = 1;
    cin >> q;
    while(++TC <= q) {
        solve();
    }
}