#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;
const int MAX_VAL = 200001;

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

    for(int i = n - 1; i > 0; i--) {
        if((a[i] % 2 == 0 && a[i - 1] % 2 == 0) || (a[i] % 2 != 0 && a[i - 1] % 2 != 0)) {
            if(a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }
        for(int j = i; j < n - 1; j++) {
            if((a[j] % 2 == 0 && a[j + 1] % 2 == 0) || (a[j] % 2 != 0 && a[j + 1] % 2 != 0)) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << nl;
}