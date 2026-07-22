class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s=s.strip()
        s=s[::-1]
        ans=0
        while (ans<len(s) and s[ans]!=" ") :
            ans+=1
        return ans
        