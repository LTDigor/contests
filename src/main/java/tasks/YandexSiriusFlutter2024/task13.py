class SegmentTreeRMQ:
    def __init__(self, size):
        self.arr = [0] * (4 * size)
        self.push = [0] * (4 * size)

        self.height = 0
        while 2 ** self.height < size:
            self.height += 1

    def get_max(self, left, right):
        return self._get_max(0, left, right, 0, 2 ** self.height - 1)

    def _get_max(self, ind, left, right, node_left, node_right):
        self._propagation(ind, node_left, node_right)

        if right < node_left or node_right < left:
            return 0

        if left <= node_left and node_right <= right:
            return self.arr[ind]

        mid = (node_left + node_right) // 2
        mx_left = self._get_max(2 * ind + 1, left, right, node_left, mid)
        mx_right = self._get_max(2 * ind + 2, left, right, mid + 1, node_right)

        return max(mx_left, mx_right)

    def update_range(self, left, right, added):
        self._update_range(0, left, right, 0, 2 ** self.height - 1, added)

    def _update_range(self, ind, left, right, node_left, node_right, added):
        self._propagation(ind, node_left, node_right)

        if right < node_left or node_right < left:
            return

        if left <= node_left and node_right <= right:
            self.arr[ind] += added
            self.push[ind] += added
            return

        mid = (node_left + node_right) // 2
        self._update_range(ind * 2 + 1, left, right, node_left, mid, added)
        self._update_range(ind * 2 + 2, left, right, mid + 1, node_right, added)
        self.arr[ind] = max(self.arr[ind * 2 + 1], self.arr[ind * 2 + 2])

    def _propagation(self, ind, node_left, node_right):
        if node_right != node_left:
            self.arr[ind * 2 + 1] += self.push[ind]
            self.arr[ind * 2 + 2] += self.push[ind]

            self.push[ind * 2 + 1] += self.push[ind]
            self.push[ind * 2 + 2] += self.push[ind]

        self.push[ind] = 0


visitors, space, period = map(int, input().split())
times = list(map(int, input().split()))

tree = SegmentTreeRMQ(max(times) + period + 1)
for t in times:
    mx = tree.get_max(t, t + period - 1)
    if mx < space:
        tree.update_range(t, t + period - 1, 1)
        print('YES')
    else:
        print('NO')

# 8 2 3
# 1 3 5 1 8 5 0 6

# 10 3 4
# 1 9 0 7 2 7 6 4 10 5
