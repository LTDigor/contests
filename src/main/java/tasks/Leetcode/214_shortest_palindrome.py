class Solution:
    def shortestPalindrome(self, s: str) -> str:
        MOD = 10 ** 9 + 7

        def save_diff(a, b):
            return (a - b + MOD) % MOD

        def save_mul(a, b):
            return (a * b) % MOD

        p = 199
        p_inv = pow(p, MOD - 2, MOD)

        s = '£'.join(s)

        n = len(s)

        pows = [1]
        for i in range(n):
            pows.append((pows[-1] * p) % MOD)

        h_left = 0
        h_right = 0

        mid = n // 2
        for i in range(mid + 1):
            h_left = (ord(s[mid - i]) + h_left * p) % MOD
            h_right = (ord(s[mid + i]) + h_right * p) % MOD
            print(s[mid - i:mid + 1], h_left, h_right)

        res_mid_ind = -1
        for i in range(mid, -1, -1):
            print(s[:i + 1], s[i:2 * i + 1][::-1])
            if h_left == h_right and s[:i + 1] == s[i:2 * i + 1][::-1]:
                res_mid_ind = i
                break
            h_left = save_diff(h_left, ord(s[i]) * pows[i])

            h_right = save_diff(h_right, ord(s[2 * i]))
            h_right = save_mul(h_right, p_inv)

            h_right = save_diff(h_right, ord(s[2 * i - 1]))
            h_right = save_mul(h_right, p_inv)

            h_right = (h_right + ord(s[i - 1]) * pows[i - 1]) % MOD

        s = s[2 * res_mid_ind + 1:][::-1] + s
        return ''.join([c for c in s if c != '£'])


print(Solution().shortestPalindrome('aacecaaa'))
