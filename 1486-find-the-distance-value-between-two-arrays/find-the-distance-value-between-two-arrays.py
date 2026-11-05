class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0
        for i in range(0, len(arr1)):
            flag = True
            for j in range(0, len(arr2)):
                if abs(arr1[i] - arr2[j]) <= d:
                    flag = False
                    break
            if flag:
                ans += 1

        return ans
