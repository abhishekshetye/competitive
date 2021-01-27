class KthLargest:

    
    def __init__(self, k: int, nums: List[int]):
        self._hp = []
        self.kth = k
        for num in nums:
            if len(self._hp) <= k or self._hp[0] < num:
                heapq.heappush(self._hp, num)
                if len(self._hp) > k:
                    heapq.heappop(self._hp)
                    

    def add(self, val: int) -> int:
        if len(self._hp) <= self.kth or self._hp[0] < val:
            heapq.heappush(self._hp, val)
            if len(self._hp) > self.kth:
                heapq.heappop(self._hp)
        return self._hp[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)