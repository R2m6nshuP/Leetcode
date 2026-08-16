class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans=""
        lst=[i for i in range(1,n+1)]
        k=k-1
        while k:
            idx=k//math.factorial(n-1)
            k=k%math.factorial(n-1)
            n=n-1
            ans+=str(lst[idx])
            lst.remove(lst[idx])
        for i in lst:
            ans+=str(i)
        return ans

        