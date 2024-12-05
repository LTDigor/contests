#include <bits/stdc++.h>

#define ll long long
#define int ll
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

const int SQRT_MAXN = 10000000; 
const int S = 100000;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;

signed main() {
  ll t, d;
  cin >> t >> d;
  
  ll right = (t + d);
  ll left = max(1LL, t - d);
  ll nsqrt = (int) sqrt (right + .0);
  for (ll i=2; i<=nsqrt; ++i)
    if (!nprime[i]) {
      primes[cnt++] = i;
      if (i * i <= nsqrt)
        for (ll j = i*i; j <= nsqrt; j += i)
          nprime[j] = true;
    }

  ll result = 0;
  for (int k=left/S, maxk=right/S; k<=maxk; ++k) {
        memset (bl, 0, sizeof bl);
        int start = k * S;
        for (int i=0; i<cnt; ++i) {
        	int start_idx = (start + primes[i] - 1) / primes[i];
        	int j = max(start_idx,2LL) * primes[i] - start;
        	for (; j<S; j+=primes[i])
        		bl[j] = true;
        }

        
        for (int i=0; i<S && start+i<=right; ++i)
        	if (!bl[i] && start + i >= left) {
        	   // cout << i + start << endl; 
        		++result;
        	}
    }
    
    // cout << result << endl;
    for (int p : primes) {
        int p2 = p * p;
        if (p2 <= right && p2 >= left && p != 1) {
            // cout << p << ' ' << p2 << endl;
            result++;
        }
    }

  cout << result << endl;
}
