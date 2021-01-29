
'''
https://codeforces.com/contest/1478/problem/A
'''

def solve(nums):
	prev = -1;
	cnt = ans = 0
	for each in nums:
		if prev == each:
			cnt += 1
			ans = max(ans, cnt)
		else:
			prev = each
			cnt = 1
	return max(cnt, ans)


if __name__ == "__main__":
	t = int(input())
	for _ in range(0, t):
		n, arr = input(), input().split(" ")
		print(solve(arr))