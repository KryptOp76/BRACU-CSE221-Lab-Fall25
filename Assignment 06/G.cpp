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

    int n; cin >> n;

    vector<string> words(n);
    vector<bool> pres(26, false);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
        for(char c : words[i]) {
            pres[c - 'a'] = true;
        }
    }

    vi g[26], inDeg(26, 0);
    for(int i = 0; i < n - 1; i++) {
        string w1 = words[i];
        string w2 = words[i + 1];

        bool diff = false;
        int len = min(sz(w1), sz(w2));

        for(int j = 0; j < len; j++) {
            if(w1[j] != w2[j]) {
                g[w1[j] - 'a'].pb(w2[j] - 'a');
                inDeg[w2[j] - 'a']++;
                diff = true;
                break;
            }
        }

        if(!diff && sz(w1) > sz(w2)) {
            cout << -1 << nl;
            return 0;
        }
    }

    priority_queue<int, vi, greater<int>> pq;
    int unqChar = 0;
    for(int i = 0; i < 26; i++) {
        if(pres[i]) {
            unqChar++;
            if(!inDeg[i]) {
                pq.push(i);
            }
        }
    }

    string ans = "";
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans += (char)(u + 'a');

        for(auto v : g[u]) {
            inDeg[v]--;
            if(!inDeg[v]) {
                pq.push(v);
            }
        }
    }

    if(sz(ans) < unqChar) {
        cout << -1 << nl;
    } else {
        cout << ans << nl;
    }
    return 0;
}