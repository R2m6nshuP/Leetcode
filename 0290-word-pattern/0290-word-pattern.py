class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        hash ={}
        hash2={}
        l=s.split(" ")
        if len(l)!=len(pattern):
            return False
        i=0
        for x in l:
            if x in hash:
                if pattern[i]!=hash[x]:
                    return False
            else:
                hash[x]=pattern[i]
            i+=1
        i=0
        for x in pattern:
            if x in hash2:
                if l[i]!=hash2[x]:
                    return False
            else:
                hash2[x]=l[i]
            i+=1
        return True
        