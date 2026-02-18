class Solution {
public:
    bool hasAlternatingBits(int n) {
        // T(n) = O(logn);
        // int curr = n % 2;
        // n /= 2;
        // while(n > 0){
        //     if(curr == n%2) return false;

        //     curr = n % 2;
        //     n /= 2;
        // }
        // return true;

        unsigned int res = n ^ (n >> 1);
        return ((res & (res+1)) == 0);
    }
};