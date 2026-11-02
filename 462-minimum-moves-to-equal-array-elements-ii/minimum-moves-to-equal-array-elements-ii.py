class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        n = len(nums)
        if n==1:
            return 0
        
        nums.sort()
        moves = 0
        mid = nums[n//2]
        for i in nums:
            moves += abs(mid-i)

        return moves  
