class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        n = len(nums)
        s = str(nums[0])+str(nums[1])
        mini = int(s)
        for i in range(2, n-1, 2):
            if(mini > int(str(nums[i]) + str(nums[i+1]))):
                mini = int(str(nums[i]) + str(nums[i+1]))

        return mini