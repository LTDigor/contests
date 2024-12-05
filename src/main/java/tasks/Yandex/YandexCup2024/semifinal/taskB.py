from functools import cache

MOD = 10 ** 9 + 7


@cache
def bin_pow(a, x):
    return pow(a, x, MOD)


n, k = map(int, input().split())
inv_2 = bin_pow(2, MOD - 2)
inv_2_pow_k = bin_pow(inv_2, k)

fact = [1] * (k + 1)
inv_fact = [1] * (k + 1)
for i in range(1, k + 1):
    fact[i] = (fact[i - 1] * i) % MOD
    inv_fact[i] = bin_pow(fact[i], MOD - 2)

comb = [1] * (k + 1)
comb_pref = [1] * (k + 1)
for i in range(1, k + 1):
    comb[i] = (fact[k] * inv_fact[i] * inv_fact[k - i]) % MOD
    comb_pref[i] = (comb_pref[i - 1] + comb[i]) % MOD


@cache
def get_prob_max(x):
    res = comb_pref[x]
    res = (res * inv_2_pow_k) % MOD
    res = bin_pow(res, n - 1)
    return res


ans = 0
for i in range(1, k + 1):
    ans += i * ((get_prob_max(i) - get_prob_max(i - 1) + MOD) % MOD)
    ans %= MOD

print(ans)
