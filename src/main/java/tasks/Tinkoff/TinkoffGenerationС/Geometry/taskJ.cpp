#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

struct Vec{
    ld x, y;

    Vec operator+(const Vec& other) const {
        return {x + other.x, y + other.y};
    }

    Vec operator-(const Vec& other) const {
        return {x - other.x, y - other.y};
    }

    ld operator*(const Vec& other) const {
        return x * other.x + y * other.y;
    }

    ld operator^(const Vec& other) const {
        return x * other.y -y * other.x;
    }

    void normalize() {
        ld len = sqrt(x*x + y*y);
        x /= len;
        y /= len;
    }
};

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

    pair<ld, ld> get_intersection(Line other) {
        ll A1 = get_A(), B1 = get_B(), C1 = get_C();
        ll A2 = other.get_A(), B2 = other.get_B(), C2 = other.get_C();

        ld x = (ld) -(C2*B1 - C1*B2) / (B1*A2 - B2*A1);
        ld y = (ld) (C2*A1 - C1*A2) / (B1*A2 - B2*A1);

        return {x, y};
    }
};

istream& operator>>(istream& inn, Vec& v) {
    inn >> v.x >> v.y;
    return inn;
}

Line get_bisect(Vec x, Vec y, Vec z) {
    Vec xy = y - x;
    xy.normalize();

    Vec xz = z - x;
    xz.normalize();

    Vec bisect_v = xy + xz;
    return {x.x, x.y, x.x + bisect_v.x, x.y + bisect_v.y};
}



signed main() {
    Vec x, y, z;
    cin >> x >> y >> z;

    Line b1 = get_bisect(x, y, z);
    Line b2 = get_bisect(y, x, z);

    pair<ld, ld> res = b1.get_intersection(b2);

    cout << fixed << setprecision(10);
    cout << res.first << " " << res.second << endl;
    return 0;
}