#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

int idx = 0;
vector<int> preOrder, inOrder, postOrder;
unordered_map<int, int> inPos;

void buildPostOrder(int l, int r) {
    if(l > r) return;
    int root = preOrder[idx++];
    int mid = inPos[root];
    buildPostOrder(l, mid - 1);
    buildPostOrder(mid + 1, r);
    postOrder.push_back(root);
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
    int n; cin >> n;

    preOrder.resize(n);
    inOrder.resize(n);
    
    for(int i = 0; i < n; i++) cin >> inOrder[i];
    for(int i = 0; i < n; i++) cin >> preOrder[i];

    for(int i = 0; i < n; i++) inPos[inOrder[i]] = i;

    buildPostOrder(0, n - 1);

    for(auto x : postOrder) cout << x << " ";
    cout << nl;
    return 0;
}