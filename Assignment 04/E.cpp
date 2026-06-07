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
    int n, m; cin >> n >> m;
    vi deg(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int u; cin >> u;
        deg[u]--;
    }
    for(int i = 0; i < m; i++) {
        int v; cin >> v;
        deg[v]++;
    }

    for(int i = 1; i <= n; i++) cout << deg[i] << " ";
    cout << nl;
    return 0;
}