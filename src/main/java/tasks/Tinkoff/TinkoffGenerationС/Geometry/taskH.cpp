#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

ld angle(const Vec& a, const Vec& b) {
    return atan2(a^b, a*b);
}

ld anglePoints(const Vec& a, const Vec& b, const Vec& c) {
    Vec ab = b - a;
    Vec ac = c - a;
    ld angleBAC = abs(angle(ab, ac));
    return angleBAC;
}

signed main() {
    Vec a, b, c;
    cin >> a >> b >> c;


    ld angleABC = anglePoints(a, b, c);
    ld angleBAC = anglePoints(b, a, c);
    ld angleCBA = anglePoints(c, b, a);

    ld res = max(angleABC, max(angleBAC, angleCBA)) * 180.0 / M_PI;

    cout << fixed << setprecision(10);
    cout << res << endl;
    return 0;
}