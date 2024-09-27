#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

struct Line{
    ll x0, y0, x1, y1;

    ll get_A() {
        return y1 - y0;
    }

    ll get_B() {
        return -(x1 - x0);
    }

    ll get_C() {
        return -x0 * (y1 - y0) + y0 * (x1 - x0);
    }

    bool contains(ll x, ll y) {
        return get_A() * x + get_B() * y + get_C() == 0;
    }

    pair<ld, ld> get_intersection(Line other) {
        ll A1 = get_A(), B1 = get_B(), C1 = get_C();
        ll A2 = other.get_A(), B2 = other.get_B(), C2 = other.get_C();

        ld x = (ld) -(C2*B1 - C1*B2) / (B1*A2 - B2*A1);
        ld y = (ld) (C2*A1 - C1*A2) / (B1*A2 - B2*A1);

        return {x, y};
    }
};

istream& operator>>(istream& inn, Line& v) {
    inn >> v.x0 >> v.y0 >> v.x1 >> v.y1;
    return inn;
}


signed main() {
    Line a, b;
    cin >> a >> b;

    if (a.get_A() * b.get_B() - a.get_B() * b.get_A() == 0) {
        cout << (a.contains(b.x0, b.y0) ? 2 : 0) << endl;
        return 0;
    }

    pair<ld, ld> res = a.get_intersection(b);

    cout << fixed << setprecision(10);
    cout << 1 << " " << res.first << " " << res.second << endl;
    return 0;
}