class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = {}
        for i in s:
            if i in mp:
                mp[i] = mp[i] + 1
            else:
                mp[i] = 1
        for i in t:
            if i in mp:
                if mp[i] == 1:
                    mp.pop(i)
                else:
                    mp[i] = mp[i] - 1
            else:
                return False
        return len(mp) == 0