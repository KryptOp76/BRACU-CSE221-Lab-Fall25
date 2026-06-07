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
const int INF = 1e9;
vector<vi> g(N);

bool vis[N];
int pi[N];
vi dis(N, INF);
void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(vis[v]) continue;
            
            q.push(v);
            vis[v] = true;
            pi[v] = u;
            dis[v] = dis[u] + 1;
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

    int n, m, s, d; cin >> n >> m >> s >> d;
    vi u(m), v(m);
    for(int i = 0; i < m; i++) cin >> u[i];
    for(int i = 0; i < m; i++) cin >> v[i];

    for(int i = 0; i < m; i++) {
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }

    for(int i = 1; i <= n; i++) sort(all(g[i]));

    bfs(s);
    if(dis[d] == INF) cout << -1 << nl;
    else {
        vi path;
        for(int cur = d; cur != s; cur = pi[cur]) {
            path.pb(cur);
        }
        path.pb(s);
        reverse(all(path));
        cout << sz(path) - 1 << nl;
        for(auto road : path) cout << road << " ";
        cout << nl;
    }
    return 0;
}