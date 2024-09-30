#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

const ll INF = 1000000002;

struct Node {
	ll mn;
	ll freq;
	ll added;

	ll l;
	ll r;
};

const ll SZ = 5000000;
ll sz = 1;
Node children[SZ];

Node pull(const Node &l, const Node &r) {
	if (l.mn < r.mn) {
		return {l.mn, l.freq, 0, -1, -1};
	}

	if (l.mn > r.mn) {
		return {r.mn, r.freq, 0, -1, -1};
	}

	return {r.mn, l.freq + r.freq, 0, -1, -1};
}

void add(Node &node, ll l, ll r, ll lq, ll rq, ll x) {
    if (l >= rq || r <= lq) {
        return;
    }

    if (lq <= l && r <= rq) {
        node.mn += x;
        node.added += x;
        return;
    }

    ll mid = (l + r) / 2;

    if (node.l == -1) {
        children[sz] = {0, mid - l, 0, -1, -1};
        node.l = sz++;
    }
    add(children[node.l], l, mid, lq, rq, x);

    if (node.r == -1) {
        children[sz] = {0, r - mid, 0, -1, -1};
        node.r = sz++;
    }
    add(children[node.r], mid, r, lq, rq, x);

    Node merged = pull(children[node.l], children[node.r]);
    node.mn = merged.mn + node.added;
    node.freq = merged.freq;
}

struct LinePoint {
	ll x, y1, y2;
	ll modifier;
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	if (n == 0) {
		return 0;
	}

	ll MN_Y = INF;
	ll MX_Y = -INF;
	vector<LinePoint> points;
	fori (n) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		points.push_back({x1, y1, y2, 1});
		points.push_back({x2, y1, y2, -1});
		MN_Y = min(y1, MN_Y);
		MX_Y = max(y2, MX_Y);
	}
	sort(points.begin(), points.end(), [](const LinePoint& a, const LinePoint& b) {
		return a.x < b.x;
	});

	ll LEN = MX_Y - MN_Y;
    children[0] = {0, LEN, 0, -1, -1};

	long long res = 0;
	fori(2*n) {
		if (i > 0) {
			ll zeros = (children[0].mn == 0) * children[0].freq;
			res += (LEN - zeros) * (points[i].x - points[i - 1].x);
		}
		add(children[0], 0, LEN, points[i].y1 - MN_Y, points[i].y2 - MN_Y, points[i].modifier);
	}
	cout << res << endl;

	return 0;
}