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

istream& operator>>(istream& inn, Vec& v) {
    inn >> v.x >> v.y;
    return inn;
}



signed main() {
    Vec x, y, z;
    cin >> x >> y >> z;

    Vec xy = y - x;
    xy.normalize();

    Vec xz = z - x;
    xz.normalize();

    Vec bisect_v = xy + xz;
    bisect_v.normalize();

    ld A = bisect_v.y;
    ld B = -bisect_v.x;
    ld C = -bisect_v.y * x.x + bisect_v.x * x.y;

    if (C < 0) {
        A = -A;
        B = -B;
        C = -C;
    }

    cout << fixed << setprecision(10);
    cout << A << " " << B << " " << C << endl;
    return 0;
}