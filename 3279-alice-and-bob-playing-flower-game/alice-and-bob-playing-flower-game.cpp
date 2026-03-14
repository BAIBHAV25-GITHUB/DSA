class Solution {
public:
    long long flowerGame(int n, int m) {
        // odd in n * even in m
        long long oe = ((long long)(n+1)/2) * (m/2);

        // even in n * odd in m
        long long eo = ((long long)n/2) * ((m+1)/2);

        return oe+eo;
    }
};