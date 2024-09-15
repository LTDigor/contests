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

    string s; cin >> s;
    string s_changed = insert_tags(s);

    ll n = s_changed.length();
    fill_p_pows(n);
    vector<ll> h = count_hash(s_changed);

    std::reverse(s_changed.begin(), s_changed.end());
    vector<ll> hr = count_hash(s_changed);

    ll res = 0;
    for (ll mid = 0; mid < n; mid++) {
        // l included, r included, start from 1
        ll l = 1, r = min(mid + 1, n - mid);
        ll midr = n - mid - 1;

        while (l <= r) {
            ll m_len = (l + r) / 2;
            if (substr_hash(h, mid, mid + m_len) != substr_hash(hr, midr, midr + m_len)) {
                r = m_len - 1;
            } else {
                l = m_len + 1;
            }
        }

        if (mid % 2 == 0) {
            // #
            res += (l - 1) / 2;
        } else {
            res += l / 2;
        }
        // cout << mid << " " << l << " " << res << endl;
    }

    ll s_len = s.length();
    ll uniq_strs = s_len * (s_len + 1) / 2 + 1 - res;

    cout << uniq_strs << endl;
    return 0;
}