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
vll colors;
vll st;

ll timer = 1;
ll color = 0;
um<ll, um<ll, ll>> graph;

void dfs (ll v, ll p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	st.push_back(v);

	for (auto [to, freq] : graph[v]) {
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
		}
	}

	if (p == -1 || graph[p][v] == 1 && fup[v] > tin[]) {
    	color++;
    	for (ll node = st.back(); ; node)
        while (st.back() != v) {
            colors[st.back()] = color;
            st.pop_back();
        }
        colors[st.back()] = color;
        st.pop_back();
	}
}

signed main() {
    ll n, m;
    cin >> n >> m;

    tin.resize(n);
    fup.resize(n);
    used.resize(n);
    colors.resize(n);

    fori (m) {
        ll frm, to;
        cin >> frm >> to;
        frm--, to--;

        if (frm == to) continue;
        graph[frm][to] += 1;
        graph[to][frm] += 1;
    }

    fori(n) {
        if (!used[i]) {
            dfs(i);
        }
    }


    vll new_colors(n);
    um<ll, ll> colors_map;
    fori(n) {
        ll x = colors[i];
        if (colors_map.count(x) == 0) {
            colors_map[x] = colors_map.size();
        }
        new_colors[i] = colors_map[x];
    }

    cout << colors_map.size() << endl;
    for (ll item : new_colors) {
        cout << item + 1 << " ";
    }
    cout << endl;

	return 0;
}