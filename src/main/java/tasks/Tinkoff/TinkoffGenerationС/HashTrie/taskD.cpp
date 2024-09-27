#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> h;
ll p = 61;
ll mod = 1e9 + 7;
vector<ll> p_pows;


template <typename T>
T mod_pow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

// l included, r excluded, start from 0
ll substr_hash(const vector<ll> &h, ll l, ll r) {
    return ((h[r] - h[l] * p_pows[r - l]) % mod + mod) % mod;
}

void fill_p_pows(ll n) {
    p_pows = vector<ll>(n + 1);
    for (ll i = 0; i <= n; i++) {
        p_pows[i] = mod_pow(p, i, mod);
    }
}

vector<ll> count_hash(const string &s) {
    ll n = s.length();
    vector<ll> h = vector<ll>(n + 1);
    for (ll i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * p + s[i - 1] - 26) % mod;
    }

    return h;
}

string insert_tags(const string &s) {
    string res = "";
    for (char c : s) {
        res += '#';
        res += c;
    }

    res += '#';
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    string p; cin >> p;
    ll np = p.length();
    vector<ll> hp = count_hash(p);

    string t; cin >> t;
    ll nt = t.length();
    vector<ll> ht = count_hash(t);

    fill_p_pows(nt);

    if (np > nt) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> res;
    for (ll start = 0; start < nt - np + 1; start++) {
        ll l = 0, r = np - 1;

        while (l <= r) {
            ll mid = (l + r) / 2;
            if (substr_hash(hp, 0, mid + 1) != substr_hash(ht, start, start + mid + 1)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l >= np - 1) {
            res.push_back(start);
            continue;
        }

        if (substr_hash(hp, l + 1, np) == substr_hash(ht, start + l + 1, start + np)) {
            res.push_back(start);
        }
    }

    cout << res.size() << endl;
    for (ll item : res) {
        cout << item + 1 << " ";
    }

    return 0;
}