#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

const int SQRT_MAXN = 1000000; 
const int S = 10000000;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;

bool check_vip(int number, int prefix) {
    int pow10 = 1;
    for (int i = 0; i < 4; i++) {
        if ((number / pow10) % 10000 == prefix) {
            return true;
        }
        pow10 *= 10;
    }
    
    return false;
}

signed main() {
	string prefix_str;
	cin >> prefix_str;
	int prefix = stoi(prefix_str);
	
	ll n = (prefix + 1) * 10000000L;
	ll nsqrt = (int) sqrt (n + .0);
	for (ll i=2; i<=nsqrt; ++i)
		if (!nprime[i]) {
			primes[cnt++] = i;
			if (i * i <= nsqrt)
				for (ll j = i*i; j <= nsqrt; j += i)
					nprime[j] = true;
		}

	ll result = 0;
	ll result_vip = 0;
	
	ll k = prefix;
	memset (bl, 0L, sizeof bl);
	ll start = k * S;
	for (int i=0; i < cnt; ++i) {
		ll start_idx = (start + primes[i] - 1) / primes[i];
		ll j = max(start_idx, 2ll) * primes[i] - start;
		for (; j<S; j+=primes[i])
			bl[j] = true;
	}
	if (k == 0)
		bl[0] = bl[1] = true;
	for (ll i=0; i<S && start+i<=n; ++i) {
		if (!bl[i]) {
			++result;
			if (check_vip((i + start) % 10000000, prefix)) {
			    result_vip++;
			}
		}
	}
	cout << result << ' ' << result_vip << endl;
}