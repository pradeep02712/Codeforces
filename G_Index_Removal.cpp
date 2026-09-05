#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        int64 k;
        cin >> n >> k;

        vector<int64> a(n);
        for (auto &x : a) cin >> x;

        // Prefix sums of a
        vector<int64> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + a[i];
        }

        // d[i] = k * i - a[i]
        // Since a[i+1] - a[i] <= k,
        // d[i+1] >= d[i], so d is nondecreasing.
        vector<int64> d(n);
        for (int i = 0; i < n; ++i) {
            d[i] = k * i - a[i];
        }

        vector<int64> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            // Removing an endpoint changes no adjacency.
            if (i == 0 || i == n - 1) {
                ans[i] = 0;
                continue;
            }

            int64 L = a[i - 1];
            int64 R = a[i + 1];

            // The new pair (L, R) is already good.
            if (L <= R && R <= L + k) {
                ans[i] = 0;
                continue;
            }

            // ------------------------------------------------------------
            // Case 1: R < L
            // We need to decrease the prefix ending at i-1
            // so that its last value becomes at most R.
            //
            // Cost = sum_{j < i} max(0, a[j] - R)
            // ------------------------------------------------------------
            if (R < L) {
                // Find first position p in [0, i)
                // such that a[p] > R.
                int p = upper_bound(a.begin(), a.begin() + i, R) - a.begin();

                int64 cnt = i - p;
                int64 sum = pref[i] - pref[p];

                ans[i] = sum - cnt * R;
            }

            // ------------------------------------------------------------
            // Case 2: R > L + k
            // We need to decrease R to T = L + k.
            //
            // For j > i:
            // b[j] = min(a[j], T + k * (j - i - 1))
            //
            // A position needs reduction iff
            // a[j] - k*j > T - k*(i+1)
            //
            // Equivalently:
            // d[j] = k*j - a[j] < k*(i+1) - T
            //
            // d[] is nondecreasing, so binary search finds
            // the last affected position.
            // ------------------------------------------------------------
            else {
                int64 target = k * (i + 1LL) - (L + k);

                // First j >= i+1 with d[j] >= target.
                int lo = i + 1, hi = n;

                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;

                    if (d[mid] >= target)
                        hi = mid;
                    else
                        lo = mid + 1;
                }

                int p = lo;

                // Affected positions are [i+1, p).
                int64 cnt = p - (i + 1LL);

                if (cnt > 0) {
                    int64 sumA = pref[p] - pref[i + 1];

                    // Sum of required values:
                    // T + (T+k) + ... progression
                    //
                    // baseline_j = T + k * (j-i-1)
                    //
                    // sum baseline =
                    // cnt*T + k * (0 + 1 + ... + cnt-1)
                    int64 Tval = L + k;
                    int64 sumOffsets = cnt * (cnt - 1) / 2;

                    int64 baselineSum = cnt * Tval + k * sumOffsets;

                    ans[i] = sumA - baselineSum;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}