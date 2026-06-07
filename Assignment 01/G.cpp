#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

void testCase() {
    int n; cin >> n;
    vector<int> id(n), marks(n);
    for(int i = 0; i < n; i++) cin >> id[i];
    for(int i = 0; i < n; i++) cin >> marks[i];

    int swaps = 0;
    for(int i = 0; i < n; i++) {
        int maxIdx = i;
        for(int j = i + 1; j < n; j++) {
            if((marks[j] > marks[maxIdx]) ||
            (marks[j] == marks[maxIdx]) && id[j] < id[maxIdx]) {
                maxIdx = j;
            }
        }
        if(maxIdx != i) {
            swap(marks[i], marks[maxIdx]);
            swap(id[i], id[maxIdx]);
            swaps++;
        }
    }

    cout << "Minimum swaps: " << swaps << nl;
    for(int i = 0; i < n; i++) {
        cout << "ID: " << id[i] << " Mark: " << marks[i] << nl;;\
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);

    int tc; cin >> tc;
    while(tc--) testCase();
    return 0;
}