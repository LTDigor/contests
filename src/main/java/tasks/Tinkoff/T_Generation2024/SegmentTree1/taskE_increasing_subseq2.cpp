#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll MOD = 1000000007;
ll n;
vll a;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    a.resize(n);
    fori(n) {
        cin >> a[i];
    }

    int d[n]; // константа MAX_N равна наибольшему возможному значению n
    int freq[n];

    for (int i=0; i<n; ++i) {
    	d[i] = 1;
    	freq[i] = 1;
    	for (int j=0; j<i; ++j) {
    		if (a[j] < a[i]) {
    		    if (d[i] < 1 + d[j]) {
    		        d[i] = 1 + d[j];
    		        freq[i] = freq[j];
    		    } else if (d[i] == d[j] + 1) {
    		        freq[i] += freq[j];
    		        freq[i] %= MOD;
    		    }
    		}
    	}
    }

    int ans = d[0];
    for (int i=0; i<n; ++i)
    	ans = max (ans, d[i]);

    int res = 0;
    for (int i=0; i<n; ++i) {
        if (d[i] == ans) {
            res += freq[i];
            res %= MOD;
        }
    }

    cout << res << endl;
    return 0;
}