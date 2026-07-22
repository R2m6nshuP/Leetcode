class Solution:
    def scoreOfString(self, s: str) -> int:
        r=0
        sum=0
        while r<len(s)-1:
            sum+=abs(ord(s[r])-ord(s[r+1]))
            r+=1
        return sum
        