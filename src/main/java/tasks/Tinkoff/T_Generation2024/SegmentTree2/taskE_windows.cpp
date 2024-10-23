#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define all(vec) vec.begin(), vec.end()
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

struct Node {
	ll mx;
	ll y;
	ll added;
};

vector<Node> t;

void push(ll p, ll l, ll r) {
    if (t[p].added == 0) {
        return;
    }

    t[p].mx += t[p].added;
    if (l + 1 < r) {
       ll pl = 2 * p + 1;
       ll pr = 2 * p + 2;

       t[pl].added += t[p].added;
       t[pr].added += t[p].added;
    }
    t[p].added = 0;
}

Node pull(ll pl, ll pr) {
    Node left = t[pl];
    Node right = t[pr];

    if (left.mx + left.added > right.mx + right.added) {
        return left;
    }

    return right;
}

void add(ll p, ll l, ll r, ll lq, ll rq, ll x) {
    push(p, l, r);
    if (l >= rq || r <= lq) {
        return;
    }

    if (lq <= l && r <= rq) {
        t[p].added += x;
        push(p, l, r);
        return;
    }

    ll mid = (r + l) >> 1;
    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    add(pl, l, mid, lq, rq, x);
    add(pr, mid, r, lq, rq, x);

    t[p] = pull(pl, pr);
}

void build (ll p, ll l, ll r) {
    if (l + 1 == r) {
        t[p] = {0, l, 0};
        return;
    }

    ll mid = (r + l) >> 1;
    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    build(pl, l, mid);
    build(pr, mid, r);
    t[p] = {0, l, 0};
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

	vector<LinePoint> points;
	vll compressed_to_y;
	fori (n) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		compressed_to_y.push_back(y1);
		compressed_to_y.push_back(y2 + 1);

		points.push_back({x1, y1, y2 + 1, 1});
		points.push_back({x2, y1, y2 + 1, -1});
	}

	sort(points.begin(), points.end(), [](const LinePoint& a, const LinePoint& b) {
	    if (a.x != b.x) {
		    return a.x < b.x;
	    }

	    return a.modifier > b.modifier;
	});

	sort(all(compressed_to_y));
	compressed_to_y.erase(unique(all(compressed_to_y)), compressed_to_y.end());

	um<ll, ll> y_to_compressed;
	ll len = compressed_to_y.size();
	fori (len) {
	    y_to_compressed[compressed_to_y[i]] = i;
	}

    t = vector<Node>(4 * len);
    build(0, 0, len);

	ll mx = 0;
	ll resx = 0, resy = 0;
	fori(2*n) {
		add(0, 0, len, y_to_compressed[points[i].y1], y_to_compressed[points[i].y2], points[i].modifier);
		if (mx < t[0].mx) {
		    mx = t[0].mx;
		    resx = points[i].x;
		    resy = compressed_to_y[t[0].y];
		}
	}
	cout << mx << endl;
	cout << resx << ' ' << resy << endl;

	return 0;
}