class Solution:
    # def solveUsingRec(self, index, amount, coins) -> int:
    #     if amount == 0:
    #         return 1

    #     if index == 0:
    #         return 1 if amount % coins[0] == 0 else 0

    #     exclude = self.solveUsingRec(index-1, amount, coins)

    #     include = 0
    #     if coins[index] <= amount:
    #         include = self.solveUsingRec(index, amount-coins[index], coins)

    #     return include+exclude

    def solveUsingMem(self, index, amount, coins, dp) -> int:
        if amount == 0:
            return 1

        if index == 0:
            return 1 if amount % coins[0] == 0 else 0

        if dp[index][amount] != -1:
            return dp[index][amount]

        exclude = self.solveUsingMem(index-1, amount, coins, dp)

        include = 0
        if coins[index] <= amount:
            include = self.solveUsingMem(index, amount-coins[index], coins, dp)

        dp[index][amount] = include+exclude
        return dp[index][amount]

    def change(self, amount: int, coins: list[int]) -> int:
        n=len(coins)
        # return self.solveUsingRec(n-1, amount, coins)

        dp = [[-1] * (amount + 1) for _ in range(n)]
        return self.solveUsingMem(n-1, amount, coins, dp)
