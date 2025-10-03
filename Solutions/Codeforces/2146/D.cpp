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
    int l, r;
    cin >> l >> r;
    
    int L = l;
    
    int sum = 0;
    vector<int> nums = vector<int>(r - l + 1, 0);
    
    while (l <= r) {
        if (l == r) {
            nums[l - L] = r;
            break;
        }
    
        int k = log2(l ^ r);
        int p = 0;
        for(int i = 30; i >=k; i--) {
            p += (1 << i) & l;
        }
    
        p |= (1 << k);
        if (r - p + 1 > p - l) {
            // cout << "case 1" << endl;
            for (int j = l; j < p; j++) {
                nums[j - L] = 2 * p - j - 1;
                nums[2 * p - j - 1 - L] = j;
            }
    
            l = 2 * p - l;
        } else {
            // cout << "case 2" << endl;
            for (int j = r; j >= p; j--) {
                nums[j - L] = 2 * p - j - 1;
                nums[2 * p - j - 1 - L] = j;
            }
    
            r = 2 * p - r - 2;
        }
    }
    
    for (int i = 0; i < size(nums); i++) {
        sum += (nums[i] | (i + L));
    }
    
    // print
    cout << sum << endl;
    for (int x : nums) cout << x << ' ';
    cout << endl;
}
    
signed main(){
    int q = 1;
    cin >> q;
    while(++TC <= q) {
        solve();
    }
}