class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0
        # for i in range(0, len(arr1)):
        #     flag = True
        #     for j in range(0, len(arr2)):
        #         if abs(arr1[i] - arr2[j]) <= d:
        #             flag = False
        #             break
        #     if flag:
        #         ans += 1

        arr2.sort()
        n = len(arr2)

        for i in range(0, len(arr1)):
            j = bisect.bisect_left(arr2, arr1[i])
            if j == 0:
                ans += (arr2[0]-arr1[i]) > d
            elif j >= n:
                ans += (arr1[i] - arr2[n-1]) > d
            else:
                ans += (arr2[j]-arr1[i]) > d and (arr1[i]-arr2[j-1]) > d

        return ans
