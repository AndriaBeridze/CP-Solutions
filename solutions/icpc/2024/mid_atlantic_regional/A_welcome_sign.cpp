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
    
void print(string s, int L, int R) {
    for (int i = 0; i < L; i++) cout << '.';
    cout << s;
    for (int j = 0; j < R; j++) cout << '.';
    cout << endl;
}

void solve() {
    int r, c;
    cin >> r >> c;

    int cnt = 0;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        int rem = c - size(s);
        int L = rem / 2, R = 0;

        if (rem % 2) L += cnt++ % 2;
        R = rem - L;

        print(s, L, R);
    }
}
    
signed main(){
    int q = 1;
    // cin >> q;
    while(++TC <= q) {
        solve();
    }
}