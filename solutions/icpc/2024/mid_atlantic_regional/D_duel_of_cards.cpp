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
    
int calc(bool* a, int n) {
    int cnt = 0, ans = 0;
    for (int i = 2 * n; i >= 1; i--) {
        if (a[i]) cnt++;
        else {
            if (cnt > 0) {
                cnt--;
                ans++;
            }
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    bool a[2 * n + 1], b[2 * n + 1];

    for (int i = 1; i <= 2 * n; i++) a[i] = false, b[i] = true;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = true;
        b[x] = false;
    }

    cout << n - calc(b, n) << ' ' << calc(a, n) << endl;
}
    
signed main(){
    int q = 1;
    // cin >> q;
    while(++TC <= q) {
        solve();
    }
}