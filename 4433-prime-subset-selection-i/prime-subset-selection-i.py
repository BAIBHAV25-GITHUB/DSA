class Solution:
    def maxPrimes(self, n: int, s: int) -> list[int]:
        sieve = [True]*(n+1)
        sieve[0] = False

        if(n >= 1):
            sieve[1] = False
        
        i = 2
        while(i*i <= n+1):
            if sieve[i]:
                for j in range(i*i, n+1, i):
                    sieve[j] = False
            i+=1
        
        ans = []
        sum_val = 0

        for i in range(2, n+1):
            if not sieve[i]:
                continue
            if sum_val+i > s:
                break
            sum_val += i
            ans.append(i) 

        return ans
        