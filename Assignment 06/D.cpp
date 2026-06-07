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

const int N = 2e5 + 10;
vi g[N];
int maxDis = -1;
int farthestNode = -1;

void dfs(int u, int p, int d) {
    if(d > maxDis) {
        maxDis = d;
        farthestNode = u;
    }
    for(auto v : g[u]) {
        if(v != p) {
            dfs(v, u, d + 1);
        }
    }
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
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1, 0);
    int endPoint1 = farthestNode;

    maxDis = -1;
    dfs(endPoint1, -1, 0);

    cout << maxDis << nl;
    cout << endPoint1 << " " << farthestNode << nl;
    return 0;
}