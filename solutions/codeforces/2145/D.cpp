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
#define inf (int) 1e1

#define N 50
int pos[N + 1][N * (N + 1) / 2 + 1];

void calc(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int p = 1; p <= i; p++) {
                if (j >= p * (p + 1) / 2) {
                    if (pos[i - p][j - p * (p + 1) / 2] != -1) {
                        pos[i][j] = p;
                    }
                }
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    k = n * (n + 1) / 2 - k;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            pos[i][j] = -1;

    pos[0][0] = 0;
    calc(n, k);

    if (pos[n][k] == -1) {
        cout << 0 << endl;
        return;
    }

    vector<int> v;
    int m = n;

    while (k) {
        int val = pos[m][k];
        v.push_back(val);
        m -= val;
        k -= val * (val + 1) / 2;
    }

    int cur = n;
    for (int x : v) {
        for (int i = cur - x + 1; i <= cur; i++) cout << i << ' ';
        cur -= x;
    }
    cout << endl;
}

signed main() {
    int q = 1;
    cin >> q;
    while (++TC <= q) {
        solve();
    }
}
