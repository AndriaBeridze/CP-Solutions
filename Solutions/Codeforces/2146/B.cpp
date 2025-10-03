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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n); 
    
    int cnt[m];
    for (int i = 0; i < m; i++) cnt[i] = 0;
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[i] = vector<int>(k, 0);
        for (int j = 0; j < k; j++) {
            cin >> v[i][j];
            cnt[v[i][j] - 1]++;
        }
    }
    
    int res = 1;
    for (int i = 0; i < m; i++) if(cnt[i] == 0) res = 0;
    if (res == 0) {
        cout << "NO" << endl;
        return;
    } 
    
    for (int i = 0; i < n; i++) {
        int p = 1;
    
        for (int j = 0; j < size(v[i]); j++) {
            if (--cnt[v[i][j] - 1] == 0) p = 0;
        }
    
        res += p;
        for (int j = 0; j < size(v[i]); j++) {
            ++cnt[v[i][j] - 1];
        }
    }
    
    cout << (res >= 3 ? "YES" : "NO") << endl;
}
    
signed main(){
    int q = 1;
    cin >> q;
    while(++TC <= q) {
        solve();
    }
}