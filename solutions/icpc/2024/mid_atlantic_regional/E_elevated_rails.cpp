#include <bits/stdc++.h>
using namespace std;

int TC = 0;

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define size(v) (int) v.size()
#define left  node * 2, l, (l + r) / 2
#define right node * 2 + 1, (l + r) / 2 + 1, r
#define inf   (int) 1e18

vector<vector<int>> g;
vector<bool> u;
vector<pair<int, int>> mx;
vector<int> num;

int cnt = 0, is[3] = {0, 0, 0};

void dfs(int node, int p = -1) {
    num[node] = cnt;
    u[node] = true;
    mx[node] = {1, -1};

    for (int to : g[node]) {
        if (to == p) continue;
        dfs(to, node);

        if (mx[to].first + 1 > mx[node].first) {
            mx[node] = {mx[to].first + 1, mx[node].first};
        } else if (mx[to].first + 1 > mx[node].second) {
            mx[node] = {mx[node].first, mx[to].first + 1};
        }
    }
}

void fix(int node, int p = -1) {
    if (p != -1) {
        int k = (mx[p].first != mx[node].first + 1 ? mx[p].first : mx[p].second) + 1;
        if (mx[node].first < k) {
            mx[node] = {k, mx[node].first};
        } else if (mx[node].second < k) {
            mx[node] = {mx[node].first, k};
        }
    }

    is[cnt] = max(is[cnt], mx[node].first);

    for (int to : g[node]) {
        if (to == p) continue;
        fix(to, node);
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    g   = vector<vector<int>>(n + 1, vector<int>(0));
    u   = vector<bool>(n + 1, false);
    mx  = vector<pair<int, int>>(n + 1, {-1, -1});
    num = vector<int>(n + 1, 0);

    for (int i = 1; i <= n - 3; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!u[i]) {
            dfs(i);
            fix(i);
            cnt++;
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << mx[a].first + mx[b].first + is[3 - num[a] - num[b]] << endl;
    }
}

signed main() {
    int q = 1;
    // cin >> q;
    while (++TC <= q) {
        solve();
    }
}
