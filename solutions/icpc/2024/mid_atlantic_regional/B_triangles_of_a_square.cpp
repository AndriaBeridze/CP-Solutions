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
    
bool is_corner(int x, int y) {
    return (x == 0 || x == 2024) && (y == 0 || y == 2024);
}

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << 2 - is_corner(x1, y1) - is_corner(x2, y2) << endl;
}
    
signed main(){
    int q = 1;
    // cin >> q;
    while(++TC <= q) {
        solve();
    }
}