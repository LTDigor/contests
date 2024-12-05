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
vll on_stack;
vll scc;
vll st;

ll timer = 1;
ll component_number = 0;
um<ll, vll> graph;

// Алгоритм Тарьяна поиска КСС
void dfs (ll at) {
	used[at] = true;
	tin[at] = fup[at] = timer++;

	st.push_back(at);
	on_stack[at] = true;

	for (ll to : graph[at]) {
		if (!used[to]) {
			dfs (to);
			fup[at] = min(fup[at], fup[to]);
		}
		if (on_stack[to]) {
            fup[at] = min(fup[at], tin[to]);
		}
	}

    if (fup[at] == tin[at]) {
    	for (ll node = st.back();;node = st.back()) {
            scc[node] = component_number;
            on_stack[node] = false;
            st.pop_back();
            if (node == at) break;
    	}
        component_number++;
    }
}

signed main() {
    ll n, m;
    cin >> n >> m;

    tin.resize(n);
    fup.resize(n);
    used.resize(n);
    scc.resize(n);
    on_stack.resize(n);

    fori (m) {
        ll frm, to;
        cin >> frm >> to;
        frm--, to--;
        graph[frm].push_back(to);
    }

    fori(n) {
        if (!used[i]) {
            dfs(i);
        }
    }

    vll new_inds(n);
    um<ll, ll> scc_map;
    fori(n) {
        ll old = scc[i];
        if (scc_map.count(old) == 0) {
            scc_map[old] = scc_map.size();
        }
        new_inds[i] = scc_map[old];
    }

    cout << scc_map.size() << endl;
    for (ll item : new_inds) {
        cout << item + 1 << " ";
    }
    cout << endl;

	return 0;
}