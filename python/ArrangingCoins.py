class Solution:
    def arrangeCoins(self, n: int) -> int:
        lo, hi = 0, n + 1
        while lo < hi:
            mi = (hi - lo) // 2 + lo
            if mi * (mi + 1) // 2 <= n:
                lo = mi + 1
            else:
                hi = mi
        return lo-1
