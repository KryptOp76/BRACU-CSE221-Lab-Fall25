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

const int N = 1e3 + 10;
char grid[N][N];
bool vis[N][N];
int r, h;

int dfs(int x, int y) {
    vis[x][y] = true;
    int cnt = (grid[x][y] == 'D' ? 1 : 0);

    if(x < r - 1 && grid[x + 1][y] != '#' && !vis[x + 1][y])
        cnt += dfs(x + 1, y);
    
    if(x > 0 && grid[x - 1][y] != '#' && !vis[x - 1][y])
        cnt += dfs(x - 1, y);

    if(y < h - 1 && grid[x][y + 1] != '#' && !vis[x][y + 1])
        cnt += dfs(x, y + 1);
    
    if(y > 0 && grid[x][y - 1] != '#' && !vis[x][y - 1])
        cnt += dfs(x, y - 1);

    return cnt;
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

    cin >> r >> h;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < h; j++) {
            cin >> grid[i][j];
        }
    }

    int maxDiamond = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < h; j++) {
            if(grid[i][j] != '#' && !vis[i][j]) {
                int cnt = dfs(i, j);
                maxDiamond = max(maxDiamond, cnt);
            }
        }
    }
    cout << maxDiamond << nl;
    return 0;
}