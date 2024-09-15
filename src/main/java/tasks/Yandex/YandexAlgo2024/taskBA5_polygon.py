from collections import namedtuple


def sign(a):
    if a == 0:
        return 0
    if a > 0:
        return 1
    return -1


Point = namedtuple('Point', ['x', 'y'])

need_check = {
    (Point(-1, -1), Point(1, 1)),
    (Point(1, -1), Point(-1, 1)),
}
need_increment = {
    (Point(0, -1), Point(1, 1)),
    (Point(1, -1), Point(1, 1)),
    (Point(1, -1), Point(0, 1)),

    (Point(1, 0), Point(1, 1)),
    (Point(1, 0), Point(0, 1)),
    (Point(1, 0), Point(-1, 1)),
}

need_decrement = {
    (Point(-1, 1), Point(1, 0)),
    (Point(0, 1), Point(1, 0)),
    (Point(1, 0), Point(1, 0)),
    (Point(1, 1), Point(1, 0)),
}

n = int(input())

start = -1
mny = 10_000
points = []
for i in range(n):
    x, y = map(int, input().split())
    if mny > y:
        mny = y
        start = i
    if len(points) >= 2 and points[-1].y == points[-2].y == y:
        points.pop()
    if len(points) >= 2 and points[-1].x == points[-2].x == x:
        points.pop()
    points.append(Point(x, y))

points = points[-2:] + points[:]

res = 0
should_decrement = False
for i in range(1, len(points) - 1):
    ab = Point(
        points[i].x - points[i - 1].x,
        points[i].y - points[i - 1].y,
    )
    bc = Point(
        points[i + 1].x - points[i].x,
        points[i + 1].y - points[i].y,
    )

    sign_ab = Point(sign(ab.x), sign(ab.y))
    sign_bc = Point(sign(bc.x), sign(bc.y))
    if (sign_ab, sign_bc) in need_check:
        product = ab.x * bc.y - ab.y * bc.x
        if product > 0:
            res += 1
    elif(sign_ab, sign_bc) in need_increment:
        if not should_decrement:
            res += 1

    if (sign_ab, sign_bc) in need_decrement:
        should_decrement = True
    else:
        should_decrement = False

print(res)
