class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        ans = set()
        for email in emails:
            val = ""  
            shouldIgnore = False
            atDone = False
            for each in email:
                if each == '@':
                    val += each
                    atDone = True
                    shouldIgnore = False
                elif (each == '.' and not atDone) or (shouldIgnore):
                    continue
                elif each == '+':
                    shouldIgnore = True
                else:
                    val += each
            ans.add(val)
        return len(ans)
                