class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long total = 0;
        if(cost1+cost2 <= costBoth){
            return (1LL*need1*cost1 + 1LL*need2*cost2);
        }
        
        long long both = min(need1, need2);
        total = both * costBoth;
        if(need1-both > 0){
            total += (need1-both) * min(cost1, costBoth);
        }
        else{
            total += (need2-both) * min(cost2, costBoth);
        }
        return total;
    }
};