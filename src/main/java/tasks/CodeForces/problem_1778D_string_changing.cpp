#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define us unordered_set
#define all(vec) vec.begin(), vec.end()
#define fori(n) for (ll i = 0; i < n; i++)

#define watch(x) cerr << #x << " " << (x) << endl;
#define cerr cerr && debug && cout
const bool debug = 0;

using namespace std;

const int MOD_ = 998244353;

template<int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt power(ll p) {
      ModInt res = 1, a = *this;
      while (p) {
          if (p & 1) res *= a;
          a *= a;
          p >>= 1;
      }
      return res;
  }

  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.power(MOD - 2); }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};

typedef ModInt<MOD_> mint;

const ll N = 1e6 + 5;
mint m[N], add[N];

void solve() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    ll counter = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            counter++;
        }
    }

    m[1] = 1;
    for (ll i = 2; i <= n; i++){
        m[i] = (m[i - 1] * n - m[i - 2] *  (i - 1)) / ((mint) n - i + 1);
        add[i] = (add[i - 1] * n - add[i - 2] *  (i - 1) - n) / ((mint) n - i + 1);
        watch(i);
        watch(m[i]);
        watch(add[i]);
    }

    mint m1 = (add[n - 1] - add[n] + 1) / (m[n] - m[n - 1]);
    mint ans = m1 * m[counter] + add[counter];
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}