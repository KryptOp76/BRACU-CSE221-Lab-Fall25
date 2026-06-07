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
vector<vi> g(N);
bool vis[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    cout << s << " ";

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(vis[v]) continue;
            
            cout << v << " ";
            q.push(v);
            vis[v] = true;
        }
    }
    cout << nl;
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
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(1);
    return 0;
}