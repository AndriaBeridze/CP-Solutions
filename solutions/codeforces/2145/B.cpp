#include <bits/stdc++.h>
using namespace std;

int TC = 0;

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define size(v) (int) v.size()
#define left node * 2, l, (l + r) / 2
#define right node * 2 + 1, (l + r) / 2 + 1, r
#define inf (int) 1e18

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int p = 0;
    int a[3] = {0, 0, 0};

    for (int i = 0; i < k; i++) {
        a[s[i] - '0']++;
        if (s[i] == '2') p++;
    }

    string ans = "";
    for (int i = 0; i < n; i++) ans += '+';

    for (int i = 0; i < a[0]; i++) ans[i] = '-';
    for (int i = n - 1; i >= n - a[1]; i--) ans[i] = '-'; 

    int e = 0, f = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '2') e++;
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == '+') f++;
    }

    if (e == f) {
        for (int i = 0; i < n; i++) cout << '-';
        cout << endl;
        return;
    }

    for (int i = a[0]; i < min(n - 1, a[0] + a[2]) && ans[i] != '-'; i++) ans[i] = '?';
    for (int j = n - a[1] - 1; j >= max(0LL, n - a[1] - a[2]) && ans[j] != '-'; j--) ans[j] = '?';

    cout << ans << endl;
}

signed main() {
    int q = 1;
    cin >> q;
    while (++TC <= q) {
        solve();
    }
}
