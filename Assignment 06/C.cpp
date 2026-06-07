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

const int N = 2e3 + 10;
int dis[N][N];
bool vis[N][N];
int n, sX, sY, eX, eY;

int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};

bool isValid(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > n) return false;
    if(vis[x][y]) return false;
    return true;
}

bool bfs() {
    queue<pii> q;
    q.push({sX, sY});
    vis[sX][sY] = true;
    dis[sX][sY] = 0;

    while(!q.empty()) {
        int currX = q.front().fi;
        int currY = q.front().se;
        q.pop();

        for(int i = 0; i < 8; i++) {
            if(isValid(currX + dx[i], currY + dy[i])) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                vis[newX][newY] = true;
                dis[newX][newY] = dis[currX][currY] + 1;
                q.push({newX, newY});

                if(newX == eX && newY == eY) return true;
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

    cin >> n;
    cin >> sX >> sY >> eX >> eY;

    if(bfs()) cout << dis[eX][eY] << nl;
    else cout << -1 << nl;
    return 0;
}