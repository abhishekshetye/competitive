class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        low = total = 0
        ans = sys.maxsize
        for high in range(0, len(nums)):
            total += nums[high]
            while total >= s and low <= high:
                ans = min(ans, high - low + 1)
                total -= nums[low]
                if low == high:
                    break
                low += 1
        return 0 if ans == sys.maxsize else ans