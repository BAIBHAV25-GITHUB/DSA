class Solution:
    def solve(self, e):
        ans = []

        for i in range(0, len(e)):
            if(e[i] == '+' or e[i] == '-' or e[i] == '*'):
                left = self.solve(e[0:i])
                right = self.solve(e[i+1:])

                for x in left:
                    for y in right:
                        if(e[i] == "+"):
                            ans.append(x+y)
                        elif(e[i] == "-"):
                            ans.append(x-y)
                        else:
                            ans.append(x*y)
        if(len(ans) == 0):
            ans.append(int(e))   

        return ans

    def diffWaysToCompute(self, expression: str) -> list[int]:
        return self.solve(expression)
        