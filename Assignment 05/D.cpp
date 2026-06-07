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

vi bfs(int s, int e, int n) {
    queue<int> q;
    q.push(s);
    vector<bool> vis(n + 1, false);
    vis[s] = true;
    vi pi(n + 1, 0);
    bool found = false;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == e) found = true;
        for(auto v : g[u]) {
            if(vis[v]) continue;

            vis[v] = true;
            q.push(v);
            pi[v] = u;
        }  
    }

    vi path;
    if(!found) return path;

    for(int now = e; now != 0; now = pi[now]) {
        path.pb(now);
    }
    reverse(all(path));
    return path;
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

    int n, m, s, d, k; cin >> n >> m >> s >> d >> k;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
    }

    vi path1 = bfs(s, k, n);
    vi path2 = bfs(k, d, n);

    if(path1.empty() || path2.empty()) cout << -1 << nl;
    else {
        cout << sz(path1) + sz(path2) - 2 << nl;
        for(auto x : path1) cout << x << " ";
        for(int i = 1; i < sz(path2); i++) {
            cout << path2[i] << " ";
        }
        cout << nl;
    }
    return 0;
}