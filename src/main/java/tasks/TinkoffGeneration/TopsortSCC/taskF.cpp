#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<ll> used, topsort, frm, to, speed, start;
ll INF = 30000000000;

void dfs(ll node) {
    used[node] = 1;
    for (ll nxt = 0; nxt < n; nxt++) {
        if (!used[nxt] &&
            frm[nxt] <= to[node] &&
            to[nxt] >= frm[node] &&
            ((frm[nxt] >= frm[node] && start[nxt] <= start[node] + speed[node] * (frm[nxt] - frm[node])) ||
            (frm[nxt] <= frm[node] && start[nxt] + speed[nxt] * (frm[node] - frm[nxt]) <= start[node]))
        ) {
            dfs(nxt);
        }
    }

    topsort.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    used.resize(n);

    for (ll i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        frm.push_back(a);
        to.push_back(b);
        start.push_back(c);
        speed.push_back(d);
    }

    for (ll i = 0; i < n; i++) {
        if (!used[i])
            dfs(i);
    }

    for (ll item : topsort) {
        cout << item + 1 << " ";
    }
    cout << endl;

    return 0;
}
