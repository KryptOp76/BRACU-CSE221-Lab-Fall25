#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> ans;
    int l = 0, r = 0;
    while(l < a.size() && r < b.size()) {
        if(a[l] < b[r]) {
            ans.push_back(a[l]);
            l++;
        } else {
            ans.push_back(b[r]);
            r++;
        }
    }

    while(l < a.size()) {
        ans.push_back(a[l]);
        l++;
    }
    while(r < b.size()) {
        ans.push_back(b[r]);
        r++;
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    cout << nl;
    return 0;   
}