#include <bits/stdc++.h>
#define ll int
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

long double angle(const Vec& a, const Vec& b) {
    return atan2(a^b, a*b);
}

signed main() {
    Vec a, o, b, p;
    cin >> a >> o >> b >> p;

    Vec oa = a - o;
    Vec ob = b - o;
    Vec op = p - o;

    long double angleOA = angle(oa, oa);
    long double angleOB = angle(ob, oa);
    long double angleOP = angle(op, oa);

    if (angleOA > angleOB) {
        swap(angleOA, angleOB);
    }

    bool res = angleOA <= angleOP && angleOP <= angleOB;
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}