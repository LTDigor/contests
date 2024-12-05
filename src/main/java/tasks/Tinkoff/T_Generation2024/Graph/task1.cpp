//#pragma GCC optimize ("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define us unordered_set
#define all(vec) vec.begin(), vec.end()
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

vll tin;
vll fup;
vll used;

ll timer = 1;
um<ll, us<ll>> graph;
set<ll> res;

void dfs (ll v, ll p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	ll children = 0;
	for (ll to : graph[v]) {
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				res.insert(v);
			++children;
		}
	}
	if (p == -1 && children > 1)
		res.insert(v);
}

signed main() {
    ll n, m;
    cin >> n >> m;

    tin.resize(n);
    fup.resize(n);
    used.resize(n);


    fori (m) {
        ll frm, to;
        cin >> frm >> to;
        frm--, to--;

        if (frm == to) continue;

        graph[frm].insert(to);
        graph[to].insert(frm);
    }

    fori(n) {
        if (!used[i]) {
            dfs(i);
        }
    }


    cout << res.size() << endl;
    for (ll item : res) {
        cout << item + 1 << " ";
    }

	return 0;
}