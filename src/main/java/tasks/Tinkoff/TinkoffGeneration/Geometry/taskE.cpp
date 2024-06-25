#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

struct Vec{
    ll x, y;

    Vec operator+(const Vec& other) const {
        return {x + other.x, y + other.y};
    }

    Vec operator-(const Vec& other) const {
        return {x - other.x, y - other.y};
    }

    ll operator*(const Vec& other) const {
        return x * other.x + y * other.y;
    }

    ll operator^(const Vec& other) const {
        return x * other.y -y * other.x;
    }
};

istream& operator>>(istream& inn, Vec& v) {
    inn >> v.x >> v.y;
    return inn;
}

bool is_intersect(const Vec& a, const Vec& b, const Vec& x, const Vec& y) {
    Vec ab = b - a;
    Vec ax = x - a;
    Vec ay = y - a;

    Vec xy = y - x;
    Vec xa = a - x;
    Vec xb = b - x;

    Vec bx = x - b;
    Vec by = y - b;

    Vec yb = b - y;
    Vec ya = a - y;

    ll ab_intersect_xy = (ab ^ ax) * (ab ^ ay);
    ll xy_intersect_ab = (xy ^ xa) * (xy ^ xb);

    if (xy_intersect_ab == 0 && ab_intersect_xy == 0) {
        return ax * ay <= 0 || bx * by <= 0 || xb * xa <= 0 || yb * ya <= 0;
    }

    return ab_intersect_xy <= 0 && xy_intersect_ab <= 0;
}

signed main() {
    Vec a, b, x, y;
    cin >> a >> b >> x >> y;

    bool res = is_intersect(a, b, x, y);
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}