class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        ans=0
        hash={}
        for i in word:
            if i.islower():
                if i not in hash:
                    if word.find(i.upper())!=-1:
                        ans+=1
                    hash[i]=1
        return ans
        