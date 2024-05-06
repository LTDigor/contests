#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> h;
ll p = 61;
ll mod = 1e9 + 7;



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
ll substr_hash(ll l, ll r) {
    return ((h[r] - h[l] * mod_pow(p, r - l, mod)) % mod + mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    ll n = s.length();
    h = vector<ll>(n + 1);
    for (ll i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * p + s[i - 1] - 26) % mod;
    }

    ll m;
    cin >> m;

    for (ll i = 0; i < m; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        bool res = substr_hash(a - 1, b) == substr_hash(c - 1, d);
        cout << (res ? "Yes" : "No") << endl;
    }
    return 0;
}