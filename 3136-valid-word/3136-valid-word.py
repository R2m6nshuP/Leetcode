class Solution:
    def isValid(self, word: str) -> bool:
        word=word.lower()
        if len(word)>=3:
            if word.isalnum():
                v=False
                c=False
                for i in word:
                    if  (i=="a" or i=="o" or i=="e" or i=="i" or i=="u"):
                        v=True
                    elif i.isalpha() :
                        c=True
                    else:
                        pass
                return v and c
        return False