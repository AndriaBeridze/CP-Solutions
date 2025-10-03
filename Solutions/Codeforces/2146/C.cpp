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
    string s;
    cin >> s;
    
    vector<int> v;
    v.push_back(0);
    v.push_back(size(s) + 1);
    for (int i = 0; i < size(s); i++) {
        if (s[i] == '1') v.push_back(i + 1);
    }
    
    sort(all(v));
    for (int i = 1; i < size(v); i++) {
        if (v[i] - v[i - 1] == 2) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES" << endl;
    
    vector<int> ans(n + 1, -1);
    for (int i = 1; i < size(v); i++) {
        int l = v[i - 1], r = v[i];
        for (int j = l + 1; j < r; j++) {
            ans[j] = l + r - j;
        }
    
        for (int j = l + 1; j < r; j++) {
            if (ans[j] == j) {
                swap(ans[j], ans[l + 1]);
                break;
            }
        }
    
        if (i != size(v) - 1) ans[v[i]] = v[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
    
signed main(){
    int q = 1;
    cin >> q;
    while(++TC <= q) {
        solve();
    }
}