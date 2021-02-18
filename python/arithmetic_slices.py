'''
https://leetcode.com/problems/arithmetic-slices/submissions/

Simple dp solution

'''

class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        dp, ans = [[0, 0] for each in A], 0
        for i in range(1, len(A)):
            dp[i][1] = A[i] - A[i-1]
            dp[i][0] = dp[i-1][0] + 1 if A[i] - A[i-1] == dp[i-1][1] else 1
            ans += dp[i-1][0] if A[i] - A[i-1] == dp[i-1][1] else 0
        return ans