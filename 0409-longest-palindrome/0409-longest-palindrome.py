class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd=False
        hash={}
        ans=0
        for i in s:
            if i in hash:
                hash[i]+=1
            else:
                hash[i]=1
        for i in hash:
            if hash[i]%2==0:
                ans+=hash[i]
            else:
                if not odd:
                    odd=True
                    ans+=1
                ans+=hash[i]-1
        return ans
        