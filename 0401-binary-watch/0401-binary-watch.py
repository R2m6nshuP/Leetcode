class Solution:
    def setbits(self,num : int) ->int:
        ans=0
        while(num):
            ans+=(num&1)
            num=num>>1
        return ans

    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans=[]
        for i in range(12):
            for j in range(60):
                if(self.setbits(j)+self.setbits(i)==turnedOn):
                    temp=""
                    temp+=str(i)+":"
                    if(j<10):
                        temp+="0"
                    temp+=str(j)
                    ans.append(temp)
        return ans