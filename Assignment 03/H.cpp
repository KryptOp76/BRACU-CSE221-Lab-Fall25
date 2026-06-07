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

void buildPreOrder(int l, int r) {
    if(l > r) return;
    int root = postOrder[idx--];
    int mid = inPos[root];
    buildPreOrder(mid + 1, r);
    buildPreOrder(l, mid - 1);
    preOrder.push_back(root);
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
    idx = n - 1;

    inOrder.resize(n);
    postOrder.resize(n);
    for(int i = 0; i < n; i++) cin >> inOrder[i];
    for(int i = 0; i < n; i++) cin >> postOrder[i];

    for(int i = 0; i < n; i++) inPos[inOrder[i]] = i;

    buildPreOrder(0, n - 1);

    reverse(all(preOrder));
    for(auto x : preOrder) cout << x << " ";
    cout << nl;
    return 0;
}