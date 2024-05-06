def dfs(cur_bank, value, currency):
    visited.add(cur_bank)

    res = 0.0
    if currency == 2:
        res = max(res, value)

    for nxt_cur in currencies:
        if nxt_cur == currency:
            continue
        nxt_val = value * g[cur_bank][currency][nxt_cur]
        if nxt_cur == 2:
            res = max(res, nxt_val)
        for nxt_bank in banks:
            if nxt_bank in visited:
                continue
            res = max(res, dfs(nxt_bank, nxt_val, nxt_cur))
    visited.remove(cur_bank)
    return res


t = int(input())

banks = [1, 2, 3]
currencies = [1, 2, 3]
g = {
    bank: {
        frm: {to: 0 for to in currencies if frm != to} for frm in currencies
    } for bank in banks
}

for _ in range(t):
    for bank in banks:
        for frm in currencies:
            for to in currencies:
                if frm == to:
                    continue
                n, m = map(int, input().split())
                g[bank][frm][to] = m / n

    res = 0.0
    visited = set()
    for start in banks:
        res = max(res, dfs(start, 1.0, 1))

    print(res)
