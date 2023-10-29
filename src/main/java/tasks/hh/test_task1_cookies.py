from unittest import TestCase
from parameterized import parameterized

from tasks.hh.task1_cookies import find_cookies


class TestSequence(TestCase):
    @parameterized.expand([
        [3, (6, 6, 8), 8],
        [6, (4, 4, 5), 3],
        [6, (4, 4, 4), 2],
    ])
    def test_find_cookies(self, m, cookies, expected):
        self.assertEqual(find_cookies(m, cookies), expected)
