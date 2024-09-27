#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

signed main() {
    ll n; cin >> n;
    vpll points;
    ll mx_x = 0;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        mx_x = max(mx_x, x);
        points.push_back({x, y});
    }

    ll x_size = mx_x + 1;

    // stores x left corner
    vll available_squares;

    ll ds = 1 << n;
    vector<bool> is_deleted(ds, false);
    for (ll i = 0; i < (1 << n); i++) {
        ll x = i * x_size;
        available_squares.push_back(x);
    }

    ll sq_ind = 0;
    for (ll point_number = 0; point_number < n; point_number++) {
        for (ll i = 0; i < (1 << (n - point_number - 1)); i++) {
            cout << "paint ";
            for (ll j = 0; j < 2; j++) {
                while (is_deleted[sq_ind]) {
                    sq_ind = (sq_ind + 1) % ds;
                }
                ll x_left = available_squares[sq_ind];
                sq_ind = (sq_ind + 1) % ds;

                ll x_painted = x_left + points[point_number].first;
                ll y_painted = points[point_number].second;

                cout << x_painted << " " << y_painted << " ";
            }
            cout << endl;

            string s;
            ll x_baned, y_baned;
            cin >> s >> x_baned >> y_baned;

            ll baned_square_ind = x_baned / x_size;
            is_deleted[baned_square_ind] = true;
        }
    }

    ll x_res;
    for (ll i = 0; i < ds; i++) {
        if (!is_deleted[i]) {
            x_res = available_squares[i];
            break;
        }
    }

    cout << "end " << x_res << " " << 0 << endl;
    return 0;
}