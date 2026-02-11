class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n);
        ans[0] = 1;

        int u2 = 0, u3 = 0, u5 = 0;
        for(int i = 1; i < n; i++){
            int next2 = ans[u2] * 2;
            int next3 = ans[u3] * 3;
            int next5 = ans[u5] * 5;

            int next = min({next2, next3, next5});
            ans[i] = next;

            if(next == next2) u2++;
            if(next == next3) u3++;
            if(next == next5) u5++;
        }

        return ans[n-1];
    }
};