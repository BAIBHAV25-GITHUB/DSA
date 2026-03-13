class Solution {
public:
    long long coloredCells(int n) {
        long long x = n;
        return (long long)(x*x) + (long long)((x-1) * (x-1));
    }
};