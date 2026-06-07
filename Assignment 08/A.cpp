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

    int n, k; cin >> n >> k;
    dsu d(n);
    while(k--) {
        int u, v; cin >> u >> v;
        d.merge(u, v);
        cout << d.get_size(u) << nl;
    }
    return 0;
}