#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl "\n"
#define all(v) v.begin(), v.end()
using ll = long long int;

const ll MOD = 0;

ll ans = 0;
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> sortedList;

    vector<ll> sqr;
    for (ll x : right) sqr.push_back(x * x);
    sort(sqr.begin(), sqr.end());
    for (ll x : left) {
        int lo = 0, hi = sqr.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(sqr[mid] < x) lo = mid + 1;
            else hi = mid;
        }
        ans += lo;
    }

    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] <= right[r]) sortedList.push_back(left[l++]);
        else sortedList.push_back(right[r++]);
    }
    while(l < left.size()) sortedList.push_back(left[l++]);
    while(r < right.size()) sortedList.push_back(right[r++]);
    return sortedList;
}

vector<int> mergeSort(vector<int>& lst, int lo, int hi) {
    if(lo == hi) return {lst[lo]};

    int mid = lo + (hi - lo) / 2;
    vector<int> left = mergeSort(lst, lo, mid);
    vector<int> right = mergeSort(lst, mid + 1, hi);

    return merge(left, right);
}

vector<int> mergeSort(vector<int>& lst) {
    if(lst.size() == 0) {
        return {};
    }
    return mergeSort(lst, 0, lst.size() - 1);
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> v = mergeSort(a);
    cout << ans << nl;
    return 0;
}