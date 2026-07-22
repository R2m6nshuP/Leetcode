class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        odd=False
        r=0
        ans=""
        while r<len(s):
            if s[r]=='1':
                if not odd:
                    odd=True
                else:
                    ans+="1"
            r+=1
        ans+="0"*(len(s)-len(ans)-1)
        ans+="1"
        return ans
        
        