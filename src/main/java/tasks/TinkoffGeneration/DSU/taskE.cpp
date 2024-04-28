#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p, s;
vector<ll> used, r;
ll n;

ll leader(ll v) {
    if (p[v] == v) {
        return v;
    }

    return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unite(ll a, ll b) {
    a = leader(a), b = leader(b);
    if (a == b)
        return;

    if (s[a] > s[b])
        swap(a, b);


    if ((r[b] + s[a]) % n == r[a]) {
        r[b] = r[a];
    }

    s[b] += s[a];
    p[a] = b;
}

void init(ll n) {
    for (ll i = 0; i < n; i++) {
        p[i] = i, s[i] = 1;
        r[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    p.resize(n);
    s.resize(n);
    r.resize(n);
    used.resize(n);

    init(n);

    for (ll i = 0; i < n; i++) {
        ll place;
        cin >> place;
        place--;

        ll next_place = place;
        while (used[next_place]) {
            unite(place, next_place);
            next_place = (r[leader(place)] + 1) % n;
        }

        used[next_place] = 1;
        cout << next_place + 1 << " ";

        while (used[next_place] && i < n - 1) {
            unite(place, next_place);
            next_place = (r[leader(place)] + 1) % n;
        }
    }
    return 0;
}