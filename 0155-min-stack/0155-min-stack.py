class MinStack:

    def __init__(self):
        self.stack = []
        self.stmin=999999

    def push(self, value: int) -> None:
        if not self.stack:
            self.stack.append(value)
            self.stmin=value
            return
        if(value<=self.stmin):
            self.stack.append(2*value-self.stmin)
            self.stmin=value
            return 
        self.stack.append(value)
        

    def pop(self) -> None:
        if(self.stack[-1]<self.stmin):
            self.stmin=2*self.stmin-self.stack[-1]
        self.stack.pop()

    def top(self) -> int:
        if(self.stack[-1]<self.stmin):
            return self.stmin
        return self.stack[-1]

    def getMin(self) -> int:
        return self.stmin


# Your Minself.stack object will be instantiated and called as such:
# obj = Minself.stack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()