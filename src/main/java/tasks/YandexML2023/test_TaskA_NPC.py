import pytest


def checkNPCs(arr, n):
    visited = [-1] * n
    for i in range(n):
        if visited[i] != -1:
            continue
        cur = i
        while arr[cur] != -1:
            if visited[cur] == i:
                return False
            if visited[cur] == -1:
                visited[cur] = i
            cur = arr[cur] - 1

    return True


@pytest.mark.parametrize("arr, expected", [([-1], True), ([1], False), ([2, 3, 4, -1], True), ([1, 3, 4, -1], False)])
def test_check_npcs(arr, expected):
    assert expected == checkNPCs(arr, len(arr))
