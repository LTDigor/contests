import math


def find_vectors_with_given_angle(v, us, t):
    angle_threshold = math.radians(t)
    indices = []
    norm_v = math.sqrt(sum(vi ** 2 for vi in v))
    for i, u in enumerate(us):
        dot_product = sum(vi * ui for vi, ui in zip(v, u))
        norm_u = math.sqrt(sum(ui ** 2 for ui in u))
        cos_angle = dot_product / (norm_v * norm_u)
        if math.acos(cos_angle) <= angle_threshold:
            indices.append(i)
    return indices if indices else [-1]


def solution():
    v = list(map(float, input().split()))
    n, t = list(map(int, input().split()))
    us = [list(map(float, input().split())) for _ in range(n)]
    answer = find_vectors_with_given_angle(v, us, t)
    print(' '.join(str(i) for i in answer))


solution()
