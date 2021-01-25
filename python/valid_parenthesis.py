class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(', '}':'{', ']':'['}
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            elif len(stack) == 0 or mp[c] != stack[len(stack) - 1]:
                return False
            else:
                stack.pop()
        return len(stack) == 0
                