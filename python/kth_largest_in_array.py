class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        self._hp = []
        self.kth = k
        for num in nums:
            if len(self._hp) <= k or self._hp[0] < num:
                heapq.heappush(self._hp, num)
                if len(self._hp) > k:
                    heapq.heappop(self._hp)
        return self._hp[0]