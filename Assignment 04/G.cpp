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

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

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

    int n, m, k; cin >> n >> m >> k;
    vector<vi> board(n + 1, vi(m + 1, 0));
    vector<pii> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i].fi >> a[i].se;
        board[a[i].fi][a[i].se] = 1;
    }
    
    for(auto [i, j] : a) {
        for(int d = 0; d < 8; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
                if(board[ni][nj]) {
                    cout << "YES" << nl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << nl;
    return 0;
}