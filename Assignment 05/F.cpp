#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

const int N = 2e5 + 10;
vector<int> g[N];
int vis[N];
bool cyclic = false;

void dfs(int u) {
    vis[u] = 1;
    for(auto v : g[u]) {
        if(cyclic) return;
        if(vis[v] == 0) {
            dfs(v);
        } else if(vis[v] == 1) {
            cyclic = true;
            return;
        }
    }
    vis[u] = 2;
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
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2; cin >> v1 >> v2;
        g[v1].push_back(v2);
    }

    for(int u = 1; u <= n; u++) {
        if(vis[u] == 0) dfs(u);
    }
    if(cyclic) cout << "YES" << nl;
    else cout << "NO" << nl;
    return 0;
}