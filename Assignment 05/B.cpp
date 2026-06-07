#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

const int N = 2e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v);
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
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    for(int i = 0; i < m; i++) cin >> u[i];
    for(int i = 0; i < m; i++) cin >> v[i];

    for(int i = 0; i < m; i++) {
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }

    dfs(1);
    return 0;
}