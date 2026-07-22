class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a=a[::-1]
        b=b[::-1]
        carry=0
        l=0
        r=0
        if len(b)>=len(a):
            a,b =b,a
        ans=""
        while(l<len(a)):
            sum=0
            sum+=carry
            carry=0
            sum+=ord(a[l])-ord('0')
            if(r<len(b)):
                sum+=ord(b[r])-ord('0')
                r+=1
            match sum:
                case 0:
                    ans+="0"
                case 1:
                    ans+="1"
                case 2:
                    ans+="0"
                    carry=1
                case 3:
                    ans+="1"
                    carry=1
            l+=1
        if carry:
            ans+="1"
        ans=ans[::-1]
        return ans

        