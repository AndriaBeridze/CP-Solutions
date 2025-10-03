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
    
const int N = 3e5 + 5;
int m[4 * N], p[4 * N];
    
void add(int node, int l, int r, int L, int R, int val) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) {
        p[node] += val;
        return;
    }
    
    p[node * 2]     += p[node];
    p[node * 2 + 1] += p[node];
    p[node] = 0;
    
    add(left, L, R, val);
    add(right, L, R, val);
    
    m[node] = max(m[node * 2] + p[node * 2], m[node * 2 + 1] + p[node * 2 + 1]);
}
    
int count(int node, int l, int r, int L, int R) {
    if (l > R || L > r) return 0;
    if (L <= l && r <= R) {
        return m[node] + p[node];
    }
    
    p[node * 2] += p[node];
    p[node * 2 + 1] += p[node];
    p[node] = 0;
    
    return max(count(left, L, R), count(right, L, R));
}
    
void solve() {
    
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        add(1, 0, n, a[i], a[i], -count(1, 0, n, a[i], a[i]));
        add(1, 0, n, 0, a[i] - 1, 1);    
        
        cout << count(1, 0, n, 0, n) << ' ';
    }
    cout << endl;
    
    for (int i = 0; i < 4 * (n + 5); i++) {
        p[i] = m[i] = 0;
    }
}
    
signed main(){
    int q = 1;
    cin >> q;
    while(++TC <= q) {
        solve();
    }
}