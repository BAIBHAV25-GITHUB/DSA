class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9*num:
            return ""
            
        nine = sum // 9
        left = sum % 9
        
        return ("9"*nine + str(left) + "0"*num)[:num]