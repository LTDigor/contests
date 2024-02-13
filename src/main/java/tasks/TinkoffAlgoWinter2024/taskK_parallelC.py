from sortedcontainers import SortedSet


def get_min_greater_than(sset, number, default_value):
    for item in sset.irange(number + 1, None):
        return item
    return default_value


def get_max_less_than(sset, number, default_value):
    for item in sset.irange(None, number - 1, reverse=True):
        return item
    return default_value


n = int(input())
arr = list(map(int, input().split()))
arr_sorted = sorted((v, i) for i, v in enumerate(arr))

res = 0
ordered_set = SortedSet()
for v, i in arr_sorted:
    left_ind = get_max_less_than(ordered_set, i, -1)
    right_ind = get_min_greater_than(ordered_set, i, n)

    res += v * (i - left_ind) * (right_ind - i)
    ordered_set.add(i)
    print(i, res, v, (i - left_ind), (right_ind - i))


print(res)

# res = 0
# for left in range(n):
#     for r in range(left, n):
#         res += min(arr[left: r + 1])
# print(res)

# 300
# -285423 451765 -894227 -572701 -334858 -918168 -876598 251922 -169885 329630 975207 288091 -675959 -357653 -155658 701718 237793 309453 -260260 728141 -802517 -193928 704317 -499710 -914146 972098 723262 -921348 537391 -471384 267053 457235 -942740 410195 2747 -24261 16304 -383040 -865889 298487 -209849 484321 105448 -629400 -924336 26032 67420 343635 88050 168791 772070 113750 -453672 986070 -1056 -66810 550415 -188471 -893846 -838577 965866 -798012 -6777 28194 -826159 -379659 -494322 -721371 321414 -296344 550607 -443886 747228 -672512 -575841 837348 655552 -892982 905896 -591597 -131682 -682040 -764181 596051 91088 611810 -125215 -605750 83213 121615 683107 -522031 91461 -631751 401773 -538159 721017 541523 105129 912719 -119460 -924034 -658274 -413934 -666988 560544 -440545 729631 -518465 -224345 928393 -114097 -839120 413752 -856368 250019 -863422 603288 287408 -974245 -964653 -620271 -95943 -586354 -531651 -520549 289910 469399 378445 433847 935873 -757327 965552 971144 370885 -295319 636115 438171 -464460 704141 57056 -630885 -945826 172877 800816 23488 -745077 -439528 360778 36975 788095 171608 -90290 788767 -988890 -948434 409307 -795259 229127 722266 -923618 87157 -83197 718394 -425584 -404722 315783 652930 668122 -244591 -697454 -63270 394057 815328 175723 -583971 810041 -588837 -902613 298263 100003 -895126 581311 158653 -772566 -320441 -130754 753512 760398 123753 129470 302524 192212 599297 -134055 -265893 -901558 844615 914976 912366 -820701 685703 850909 225122 -666621 -428696 877906 508566 -735509 -529858 936928 -491484 596732 -951241 610434 85760 985021 783385 -614888 845144 -874406 674408 964276 250617 -843135 -476487 -549937 -775581 -608564 365514 -685143 -723049 9387 -121725 -523373 440500 -795865 -717154 741569 396262 64657 714739 110285 321543 145783 -949955 -527634 401500 501770 883231 524642 -225170 879509 769237 -475381 813935 466196 -329097 -753395 113146 -43271 888488 -170685 174925 -373437 962866 -65058 -962371 433614 939854 -219532 707832 -310026 814547 -317181 -743598 903104 -59452 -44323 381454 927976 898970 556221 -578200 456273 -817573 800657 -112828 -813320 -166033 213819 101196 -10567 -944738 -704401 -725977 417876 448019 -151225 258011
