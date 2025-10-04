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
    int n, d, c;
    cin >> n >> d >> c;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int lo = 0, hi = 0;

    int l = 0, r = d;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int cur = c;

        bool th = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) {
                cur -= (mid - a[i]);
                if (cur < 0) {
                    th = false;
                    break;
                }
            } else {
                cur += min(a[i] - mid, c - cur);
            }
        }

        if (th) l = mid;
        else r = mid - 1;
    }
    lo = l;

    l = 0, r = d;
    while (l < r) {
        int mid = (l + r) / 2;
        int cur = 0;

        bool th = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                cur += (a[i] - mid);
                if (cur > c) {
                    th = false;
                    break;
                }
            } else {
                cur -= min(mid - a[i], cur);
            }
        }

        if (th) r = mid;
        else l = mid + 1;
    }
    hi = r;
    
    // cout << lo << ' ' << hi << endl;
    cout << max(0LL, hi - lo) << endl;
}
    
signed main(){
    int q = 1;
    // cin >> q;
    while(++TC <= q) {
        solve();
    }
}