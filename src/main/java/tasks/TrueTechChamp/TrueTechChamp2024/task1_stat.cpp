#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;

    multiset<ll> st;
    fori (n) {
        ll x;
        cin >> x;
        st.insert(x);
    }

    fori (n - 1) {
        auto it = st.end();
        --it;
        ll mx = *it;
        st.erase(it);

        it = st.end();
        --it;
        ll nxt = *it;
        st.erase(it);

        st.insert(mx - nxt);
    }

    cout << *st.rbegin() / 2 << endl;
	return 0;
}