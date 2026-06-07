#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define fi first
#define se second
#define pb push_back
using ll = long long int;
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
using vi = vector<int>; using vll = vector<ll>;
using pii = pair<int,int>; using pll = pair<ll,ll>;

const ll MOD = 0;

const int N = 2e3 + 10;
vi g[N];

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

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(gcd(i, j) == 1) g[i].pb(j);
        }
    }

    while(q--) {
        int x, k; cin >> x >> k;
        if(k <= sz(g[x])) cout << g[x][k - 1] << nl;
        else cout << -1 << nl;
    }
    return 0;
}