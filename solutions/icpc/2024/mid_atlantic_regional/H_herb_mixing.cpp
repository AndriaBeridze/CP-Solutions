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
    int g, r;
    cin >> g >> r;
    int ans = min(g, r) * 10;
    g -= ans / 10; r -= ans / 10;

    int val[4] = {-1, 1, 3, 10};
    for (int i = 3; i >= 1; i--) {
        ans += g / i * val[i];
        g %= i;
    }
    
    cout << ans << endl;
}
    
signed main(){
    int q = 1;
    // cin >> q;
    while(++TC <= q) {
        solve();
    }
}