#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

vector<int> a, ans;
void minimumHeight(int l, int r) {
    if(l > r) return;
    int mid = l + (r - l) / 2;
    ans.push_back(a[mid]);
    minimumHeight(l, mid - 1);
    minimumHeight(mid + 1, r);
}

void testCase() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    // int tc; cin >> tc;
    // while(tc--) testCase();
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    minimumHeight(0, n - 1);
    for(auto x : ans) cout << x << " ";
    cout << nl;
    return 0;
}