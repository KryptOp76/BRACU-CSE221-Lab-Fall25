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

struct dsu {
    vi par, rnk, size; int c;
    dsu(int n) : par(n + 1), rnk(n + 1), size(n + 1, 1), c(n) {
        for(int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
    bool same(int i, int j) { return find(i) == find(j); }
    int get_size(int i) { return size[find(i)]; }
    int count() { return c; }
    int merge(int i, int j) {
        if((i = find(i)) == (j = find(j))) return -1; else --c;
        if(rnk[i] > rnk[j]) swap(i, j);
        par[i] = j; size[j] += size[i];
        if(rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

const int N = 1e3 + 10;
vector<pii> g[N];

bool getMaxOnPath(int u, int target, int p, int limit, int &maxVal) {
    if(u == target) return true;

    for(auto &[v, w] : g[u]) {
        if(v != p) {
            if(getMaxOnPath(v, target, u, limit, maxVal)) {
                if(w < limit) {
                    maxVal = max(maxVal, w);
                }
                return true;
            }
        }
    }
    return false;
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
    vector<array<int, 3>> ed;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        ed.pb({w, u, v});
    }

    sort(all(ed));

    dsu d(n);
    ll mstWeight = 0;
    vector<bool> presentEd(m, false);
    
    for(int i = 0; i < m; i++) {
        int w = ed[i][0];
        int u = ed[i][1];
        int v = ed[i][2];

        if(d.merge(u, v) != -1) {
            mstWeight += w;
            presentEd[i] = true;
            g[u].pb({v, w});
            g[v].pb({u, w});
        }
    }

    if(d.count() > 1) {
        cout << -1 << nl;
        return 0;
    }

    ll secondBest = -1;
    for(int i = 0; i < m; i++) {
        if(!presentEd[i]) {
            int w = ed[i][0];
            int u = ed[i][1];
            int v = ed[i][2];

            int maxRemovable = -1;

            getMaxOnPath(u, v, -1, w, maxRemovable);

            if(maxRemovable != -1) {
                ll candidateWeight = mstWeight - maxRemovable + w;
                if(secondBest == -1 || candidateWeight < secondBest) {
                    secondBest = candidateWeight;
                }
            }
        }
    }
    cout << secondBest << nl;
    return 0;
}