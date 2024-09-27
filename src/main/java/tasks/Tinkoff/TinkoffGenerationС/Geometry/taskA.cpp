#include <bits/stdc++.h>
#define ll int
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
    Vec a, b, c;
    cin >> a >> b >> c;

    Vec ab = b - a;
    Vec ac = c - a;
    double res = 0.5 * abs(ab ^ ac);
    cout << res << endl;
    return 0;
}