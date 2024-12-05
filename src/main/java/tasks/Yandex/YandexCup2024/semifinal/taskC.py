n, m, q = map(int, input().split())
graph = [[0] * n for _ in range(n)]

MOD = 10 ** 9 + 7

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1

    graph[u][v] = 1
    graph[v][u] = 1

MX_POW = 25
matrix_pows = [0]

matrix_pows[0] = [row[:] for row in graph]
for p in range(1, MX_POW + 1):
    cur = [[0] * n for _ in range(n)]
    prev = matrix_pows[-1]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                cur[i][j] += prev[i][k] * prev[k][j]
                cur[i][j] %= MOD
    matrix_pows.append(cur)

for _ in range(q):
    u, k = map(int, input().split())
    u -= 1

    res_row = [0] * n
    res_row[u] = 1

    p = 0
    while k > 0:
        if k % 2 == 1:
            cur = [0] * n
            for i in range(n):
                for j in range(n):
                    cur[i] += res_row[j] * matrix_pows[p][j][i]
                    cur[i] %= MOD
            res_row = cur
        k //= 2
        p += 1

    res = sum(res_row) % MOD
    print(res)
