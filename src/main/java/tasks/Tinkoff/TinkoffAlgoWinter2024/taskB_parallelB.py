# def prefix_function(s):
#     sl = len(s)
#     pref = [0] * sl
#
#     for i in range(1, sl):
#         k = pref[i - 1]
#         while k > 0 and s[i] != s[k]:
#             k = pref[k - 1]
#         if s[i] == s[k]:
#             k += 1
#         pref[i] = k
#     return pref
#
#
# def kmp(platform, t):
#     pl = len(platform)
#     tl = len(t)
#
#     answer = []
#     pref = prefix_function(platform + "#" + t)
#
#     for i in range(tl + 1):
#         if pref[pl + i] == pl:
#             answer.append(i - pl)
#
#     return answer
#
#
# print(kmp('abra', 'abracadabra'))
