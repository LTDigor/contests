from collections import deque


def find_path(grid, start, finish):
    dirs = ((1, 0), (0, 1), (-1, 0), (0, -1))
    rows, cols = len(grid), len(grid[0])

    q = deque([(start, 0)])
    grid[start[0]][start[1]] = 1
    while q:
        (row, col), dist = q.popleft()
        if (row, col) == finish:
            return dist

        for d_row, d_col in dirs:
            n_row, n_col = row + d_row, col + d_col
            if 0 <= n_row < rows and 0 <= n_col < cols and grid[n_row][n_col] == 0:
                grid[n_row][n_col] = 1
                q.append(((n_row, n_col), dist + 1))

    return 0


def main():
    N, M = map(int, input().split())
    x_start, y_start = map(int, input().split())
    x_end, y_end = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(list(map(int, input().split())))
    print(find_path(grid, (y_start, x_start), (y_end, x_end)))


if __name__ == '__main__':
    main()
